/**
  ******************************************************************************
  * @file    show.h
  * @author  Zhang Yifa 202311998186
  * @version V2.5.4
  * @date    2024-05-21
  * @brief   show
  * @encode  GB2312
  ******************************************************************************
  */

  /* Define to prevent recursive inclusion ------------------------------------ */
#ifndef __SHOW_H
#define __SHOW_H

/* Includes ----------------------------------------------------------------- */
#include <iostream>
#include <string>
using namespace std;
#include "Expression.h"

/* Global Mode Flags -------------------------------------------------------- */
enum MODE {
	MODE_ARG,
	MODE_CLI,
};
extern MODE global_mode;

enum ARG_MODE {
	ARG_MODE_SILENT,
	ARG_MODE_COUNT,
};

enum CLI_MODE {
	CLI_MODE_SILENT,
	CLI_MODE_COUNT,
};

/* Keyword Tables ----------------------------------------------------------- */
enum CMD {
	CMD_EXIT,
	CMD_EXIT_SHORT,
	CMD_TEST,
	CMD_TEST_SHORT,
	CMD_HELP,
	CMD_HELP_SHORT,
	CMD_SILENT,
	CMD_SILENT_SHORT,
	CMD_DETAILED,
	CMD_DETAILED_SHORT,
	CMD_COUNT,
};
enum ARGS {
	ARGS_S,
	ARGS_SILENT,
	ARGS_H,
	ARGS_HELP,
	ARGS_T,
	ARGS_TEST,
	ARGS_D,
	ARGS_DETAILED,
	ARGS_E,
	ARGS_ECHO,
	ARGS_COUNT,
};

/* Exported Values ---------------------------------------------------------- */
extern bool arg_mode[ARG_MODE_COUNT];
extern bool cli_mode[CLI_MODE_COUNT];
extern const string tests[9];
extern const string cmds[CMD_COUNT];
extern const string args[ARGS_COUNT];

/* Exported functions ------------------------------------------------------- */
bool arg_detector(string s);
bool cmd_detector(string s);

bool is_arg(string s);
bool is_cmd(string s);

void show(const Expression& e);

template<unsigned N>
void test(const string(&tests)[N]) {
	for (int i = 0; i < N; i++) {
		cout << "Test " << i+1 << ": " << tests[i];
		try {
			if (global_mode == MODE_ARG) {
				if (arg_mode[ARG_MODE_SILENT])
					cout << " = " << Expression::eval(tests[i]) << endl;
				else
					cout << endl, show(Expression(tests[i]));
			}
			else {
				if (cli_mode[CLI_MODE_SILENT])
					cout << " = " << Expression::eval(tests[i]) << endl;
				else
					cout << endl, show(Expression(tests[i]));
			}
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	}

}
#endif /* !__SHOW_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
