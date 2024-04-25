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
	RMB rmb1,rmb2;
	cout << "请构造两个人民币：";
	cin >> rmb1>> rmb2;

	while (1) {
		char command;
		cout << "请选择运算(A:+/S:-/Q:++i/H:i++/J:--i/K:i--/): ";
		cin >> command;
		switch (command){
		case 'A':
			[[fallthrough]];
		case 'a':
			cout << rmb1 << "+" << rmb2 << "=" << rmb1 + rmb2 << endl;
			break;
		case 'S':
			[[fallthrough]];
		case 's':

			break;
		case 'Q':
			[[fallthrough]];
		case 'q':

			break;
		case 'H':
			[[fallthrough]];
		case 'h':

			break;
		case 'J':
			[[fallthrough]];
		case 'j':

			break;
		case 'K':
			[[fallthrough]];
		case 'k':

			break;
		default:
			break;
		}
	}
	cout << rmb1;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
