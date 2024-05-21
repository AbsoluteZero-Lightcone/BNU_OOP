/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.1.0
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

enum CMD {
	CMD_EXIT,
	CMD_TEST,
	CMD_COUNT,
};
const string cmds[] = {
	"exit",
	"test",
};
bool cmd_detector(string s) {
	for (int i = 0; i < CMD_COUNT; i++) {
		if (s == cmds[i]) {
			switch (i) {
			case CMD_EXIT:
				exit(0);
				break;
			case CMD_TEST:
				test(tests);
				break;
			}
			return true;
		}
	}
	return false;
}

int main() {
	cout << "Supported operators: + - * / ^ % test exit" << endl;
	do {
		string s;
		cout << "Input an expression: " << endl << ">>> ";
		cin >> s;
		if (cmd_detector(s))continue;
		try {
			show(Expression(s));
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	} while (true);
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
