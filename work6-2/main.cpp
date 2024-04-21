/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-21
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
#include "AlarmClock.h"

bool isContinue();

int main() {
	// 闹钟走多长时间封装在AlarmClock类里不是很合理，
	// 因为没有那个闹钟需要设计一个 一到规定时间就不走了 的功能
	// 如果要实现的话，也要把走多长时间实现在类外
	// 
	// 并且走多长时间这个需求，应该是为了避免程序一直响而采取的妥协的方法，
	// 但实际上应该是响铃之后钟继续走才对，这里实现了这一功能（只响铃10秒）
	do {
		int a, b, c, d, e;
		cout << "请输入初始时间（时 分 秒）：";
		cin >> a >> b >> c;
		cout << "请输入闹铃时间（时 分）  ：";
		cin >> d >> e;
		AlarmClock alarm(a, b, c, d, e);
		cout << "请输入计时时长（分 秒）  ：";
		cin >> a >> b;
		Clock current(0, 0, 0);
		Clock target(0, a, b);
		while (current < target) {
			current++;
			cout << alarm << "\r";
			Sleep(1000);
			cout << "                         \r";
			alarm.Tick();
		}
	} while (isContinue());

	return 0;
}

bool isContinue() {
	while (1) {
		cout << "计时结束，还要继续吗（Y/N）？";
		char command;
		cin >> command;
		if (command == 'Y' || command == 'y')return 1;
		else if (command == 'N' || command == 'n')return 0;
		else cout << "Invalid Command" << endl;
	}
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
