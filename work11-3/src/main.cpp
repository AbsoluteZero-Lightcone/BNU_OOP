/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.2.8
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
		bool silent = false;
		for (int i = 1; i < argc; i++) {// 参数解析
			if (string(argv[i]) == "-s" || string(argv[i]) == "--silent")
				silent = true;// 静默模式
		}
		if (silent)
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

	cout << "eval 2.2.8" << endl;
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
