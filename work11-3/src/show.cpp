/**
  ******************************************************************************
  * @file    show.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.4.9
  * @date    2024-05-21
  * @brief   show
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ----------------------------------------------------------------- */
#include "show.h"

/* Global Mode Flags -------------------------------------------------------- */
bool arg_mode[ARG_MODE_COUNT] = {
	true,
};
bool cli_mode[CLI_MODE_COUNT] = {
	false,
};
/* Exported Values ---------------------------------------------------------- */
const string tests[] = {
	// verified functions:
	"1 + ((2.15)) *( 300^(-0.56)%5.35/ ((2.1*(1-6)*(-2))^(0.12)+2.1) / (3 /(-2.12))*1.5)*3-6",// һ��ı��ʽ
	"1 + 2      .  2",// ���Կո�
	"123",// ��������
	"((((()))))" ,// �жϿ�����
	"-1+2",
	"1+(-2)",// ������ -1+2 �� 1+(-2)
	"1/(2-2)"// ������
	"2(3+4)",// �˺�ʡ�Ե�����Ƿ� 2(3+4)
	"2^3",// ������֧��
	"2%3",// ����ȡ������fmod֧��

	// todos:
	//"1++++----2",// todo ��鲻�Ϸ��������Ӽ���
	//"sin(123)",// todo ����ʽ����֧��
	//"|-12|",// todo ����������ţ�����ֵ��
	//"12!",// todo ���õ�Ŀ����(�׳�����)
	//"E^(i*Pi)",// todo ��ѧ����
	//"ans+1",// todo ���书��
};

const string cmds[CMD_COUNT] = {
	"exit",
	"x",
	"test",
	"t",
	"help",
	"h",
	"silent",
	"s",
	"detailed",
	"d",
};
const string args[ARGS_COUNT] = {
	"-s",
	"--silent",
	"-h",
	"--help",
	"-t",
	"--test",
	"-d",
	"--detailed",
	"-e",
	"--echo"
};
/* Private functions -------------------------------------------------------- */
void arg_help() {
	cout << "Usage: eval [options] [expression]" << endl;
	cout << "Options:" << endl;
	cout << "  -s, --silent    Silent mode, only output the result" << endl;
	cout << "  -h, --help      Show this help document" << endl;
	cout << "  -t, --test      Run test cases" << endl;
	cout << "  -d, --detailed  Show detailed information" << endl;
	cout << "  -e, --echo      Same as --detailed" << endl;
}
void help() {
	cout << endl;
	cout << "-- Help Document ---------------------------------------------------------------" << endl << endl;
	cout << "eval 2.4.9" << endl << endl;
	cout << "Supproted arguments: " << endl << endl;
	arg_help();
	cout << endl;
	cout << "Supported operators:  + - * / ^ %" << endl << endl;
	cout << "Supported shell-like cmds:  test(t) exit(x) silent(s) detailed(d) help(h)" << endl;
	cout << "  Type 'test' or 't' to run tests" << endl;
	cout << "  Type 'exit' or 'x' to exit" << endl;
	cout << "  Type 'silent' or 's' to switch to silent mode" << endl;
	cout << "  Type 'detailed' or 'd' to switch to detailed mode" << endl;
	cout << "  Type 'help' or 'h' to show help document" << endl << endl << endl;
	cout << "Find the git repository online at: " << endl << endl;
	cout << "  github.com/AbsoluteZero-Lightcone/BNU_OOP-2024" << endl << endl;
	cout << "                                                       2024-05-21, version 2.4.9" << endl;
	cout << "---------------------------------- Zhang Yifa | Absolute Zero Studio - Lightcone" << endl;
	cout << endl;
}
/* Exported functions ------------------------------------------------------- */
bool is_arg(string s){
	for (int i = 0; i < ARGS_COUNT; i++) {
		if (s == args[i])return true;
	}
	return false;
}
bool is_cmd(string s) {
	for (int i = 0; i < CMD_COUNT; i++) {
		if (s == cmds[i])return true;
	}
	return false;
}
bool arg_detector(string s) {
	for (int i = 0; i < ARGS_COUNT; i++) {
		if (s == args[i]) {
			switch (i) {
			case ARGS_H:
			case ARGS_HELP:
				arg_help();
				exit(0);// help��ֱ���˳������������Ĳ��������Ҳ���ִ�б��ʽ
				break;
			case ARGS_T:
			case ARGS_TEST:
				test(tests);
				break;
			case ARGS_S:
			case ARGS_SILENT:
				arg_mode[ARG_MODE_SILENT] = true;
				break;
			case ARGS_D:
			case ARGS_DETAILED:
				arg_mode[ARG_MODE_SILENT] = false;
				break;
			case ARGS_E:
			case ARGS_ECHO:
				arg_mode[ARG_MODE_SILENT] = false;
				break;
			default:
				break;
			}
		return true;
		}
	}
	return false;
}
bool cmd_detector(string s) {
	for (int i = 0; i < CMD_COUNT; i++) {
		if (s == cmds[i]) {
			switch (i) {
			case CMD_EXIT:
			case CMD_EXIT_SHORT:
				exit(0);
				break;
			case CMD_TEST:
			case CMD_TEST_SHORT:
				test(tests);
				break;
			case CMD_HELP:
			case CMD_HELP_SHORT:
				help();
				break;
			case CMD_SILENT:
			case CMD_SILENT_SHORT:
				cli_mode[CLI_MODE_SILENT] = true;
				break;
			case CMD_DETAILED:
			case CMD_DETAILED_SHORT:
				cli_mode[CLI_MODE_SILENT] = false;
				break;
			}
			return true;
		}
	}
	return false;
}

void show(const Expression& e) {
	cout << endl << "-- Calculating process ---------------------------------------------------------" << endl << endl;
	double res = Expression::Process(e);
	cout << endl << "------------------------------------------------------- Calculation completed --" << endl;
	cout << endl << ">>> " << e << " = " << res << endl << endl;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
