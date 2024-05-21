/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.2.4
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
	// 接受参数，支持pipeline
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			try {
				show(Expression(argv[i]));
			}
			catch (const char* err) {
				cerr << endl << "[Error] " << err << endl << endl;
			}
		}
		return 0;
	}

	cout << "Supported keywords: + - * / ^ % test exit help" << endl;
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
