/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.2.9
  * @date    2024-05-16
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;

#include "Expression.h"
#include "show.h"
bool arg_mode_silent = true;
const string args[] = {
	"-s",
	"--silent",
	"-h",
	"--help",
	"-t",
	"--test",
	"-d",
	"detailed",
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
	ARGS_COUNT,
};
void arg_help() {
	cout << "Usage: eval [options] [expression]" << endl;
	cout << "Options:" << endl;
	cout << "  -s, --silent    Silent mode, only output the result" << endl;
	cout << "  -h, --help      Show this help document" << endl;
	cout << "  -t, --test      Run test cases" << endl;
	cout << "  -d, detailed    Show detailed information" << endl;
}
bool arg_detector(string s) {
	for (int i = 0; i < ARGS_COUNT; i++) {
		if (s == args[i]) {
			switch (i) {
			case ARGS_H:
			case ARGS_HELP:
				arg_help();
				break;
			case ARGS_T:
			case ARGS_TEST:
				test(tests);
				break;
			case ARGS_S:
			case ARGS_SILENT:
				arg_mode_silent = true;
				break;
			case ARGS_D:
			case ARGS_DETAILED:
				arg_mode_silent = false;
				break;
			default:
				break;
			}
		}
		return true;
	}
	return false;
}
int main(int argc, char** argv) {
	if (argc > 1) { // 接受参数，支持pipeline
		for (int i = 1; i < argc; i++)	arg_detector(argv[i]);// 参数解析
		if (arg_mode_silent)
			for (int i = 1; i < argc; i++) {
				if (string(argv[i]) == "-s" || string(argv[i]) == "--silent")continue;
				if (cmd_detector(argv[i]))continue;
				try { cout << Expression::eval(argv[i]) << endl; }
				catch (const char* err) {}
			}
		else
			for (int i = 1; i < argc; i++) {
				if (string(argv[i]) == "-s" || string(argv[i]) == "--silent")continue;
				if (cmd_detector(argv[i]))continue;
				try { show(Expression(argv[i])); }
				catch (const char* err) {
					cerr << endl << "[Error] " << err << endl << endl;
				}
			}
		return 0;
	}

	cout << "eval 2.2.9" << endl;
	cout << "For help, type \"help\"." << endl;
	cout << endl;
	do {
		string s;
		cout << "Input an expression: " << endl << ">>> ";
		cin >> s;
		if (cmd_detector(s))continue;
		try {
			show(Expression(s));
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err;
			cout << endl << "        Type 'help' or 'h' to show help document" << endl << endl;
		}
	} while (true);
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
