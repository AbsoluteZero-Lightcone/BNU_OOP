/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.5.4
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

int main(int argc, char** argv) {
	if (argc > 1) { // 接受参数，支持pipeline
		global_mode = MODE_ARG;
		for (int i = 1; i < argc; i++)
			arg_detector(argv[i]);// 参数解析前置
		for (int i = 1; i < argc; i++) {
			if (is_arg(argv[i]))continue;// 跳过已经处理过的参数
			if(cmd_detector(argv[i]))continue;// 按顺序命令解析
			try {
				if (arg_mode[ARG_MODE_SILENT])
					cout << Expression::eval(argv[i]) << endl;
				else show(Expression(argv[i]));
			}
			catch (const char* err) {
				cerr << endl << "[Error] " << err;
				cerr << endl << "        For help, use \"eval -h\"" << endl << endl;
			}
		}
		return 0;
	}

	cout << "eval 2.5.4" << endl;
	cout << "For help, type \"help\"." << endl;
	cout << endl;
	global_mode = MODE_CLI;
	do {
		string s;
		if (!cli_mode[CLI_MODE_SILENT])
			cout << "Input an expression: "<< endl;
		cout  << ">>> ";
		getline(cin, s);
		if (cmd_detector(s))continue;
		try {
			if (cli_mode[CLI_MODE_SILENT])
				cout << Expression::eval(s) << endl;
			else
				show(Expression(s));
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err;
			cerr << endl << "        Type 'help' or 'h' to show help document" << endl << endl;
		}
	} while (true);
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
