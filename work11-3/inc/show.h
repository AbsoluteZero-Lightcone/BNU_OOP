/**
  ******************************************************************************
  * @file    show.h
  * @author  Zhang Yifa 202311998186
  * @version V2.2.1
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

/* Exported variables ------------------------------------------------------- */
extern const string tests[14];

enum CMD {
	CMD_EXIT,
	CMD_TEST,
	CMD_COUNT,
};
extern const string cmds[CMD_COUNT];

/* Exported functions ------------------------------------------------------- */
bool cmd_detector(string s);
void show(const Expression& e);

template<class T, unsigned N>
void test(T(&tests)[N]) {
	for (int i = 0; i < N; i++) {
		cout << "Test " << i << ": " << tests[i] << endl;
		try {
			show(Expression(tests[i]));
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	}

}
#endif /* !__SHOW_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
