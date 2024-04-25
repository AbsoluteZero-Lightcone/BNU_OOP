/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;
#include "RMB.h"

int main() {
	RMB rmb1, rmb2;
	cout << "请构造两个人民币：";
	cin >> rmb1 >> rmb2;
	bool isContinue = 1;
	while (isContinue) {
		char command;
		cout << "请选择运算(A:+/S:-/Q:++i/H:i++/J:--i/K:i--/): ";
		cin >> command;
		switch (command) {
		case 'A':
			[[fallthrough]]; // C++17 特性
		case 'a':
			cout << rmb1 << "+" << rmb2 << "=" << rmb1 + rmb2 << endl;
			break;
		case 'S':
			[[fallthrough]];
		case 's':
			cout << rmb1 << "-" << rmb2 << "=" << rmb1 - rmb2 << endl;
			break;
		case 'Q':
			[[fallthrough]];
		case 'q':
			cout << "++" << rmb1 << "=" << ++rmb1 << endl;
			cout << "人民币1：" << rmb1 << endl;
			break;
		case 'H':
			[[fallthrough]];
		case 'h':
			cout << rmb1 << "++" << "=" << rmb1++ << endl;
			cout << "人民币1：" << rmb1 << endl;
			break;
		case 'J':
			[[fallthrough]];
		case 'j':
			cout << "--" << rmb1 << "=" << --rmb1 << endl;
			cout << "人民币1：" << rmb1 << endl;
			break;
		case 'K':
			[[fallthrough]];
		case 'k':
			cout << rmb1 << "--" << "=" << rmb1-- << endl;
			cout << "人民币1：" << rmb1 << endl;
			while (1) {
				cout << "您还要继续吗？(Y/N): ";
				cin >> command;
				if (command == 'n' || command == 'N') {
					isContinue = 0;
					break;
				}
				else if (command == 'y' || command == 'Y') {
					break;
				}
				else {
					cerr << "Invalid command." << endl;
				}
			}
			break;
		default:
			cerr << "Invalid command." << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
