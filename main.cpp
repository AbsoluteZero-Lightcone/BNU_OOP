/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa
  * @version V1.3.2
  * @date    2024-03-06
  * @brief   A demonstration of the class Date.
  * @encode  UTF-8
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;

#include "date.h"

// 用回调函数实现了在类外自定义输出格式
void output_date1(int year, int month, int day) {
	cout << "date1 = " << year << "年" << month << "月" << day << "日" << endl;
}
void output_date1(string s) {
	cout << "date1回调函数接口提示信息：" << s << endl;
}
void output_date2(int year, int month, int day) {
	cout << "date2 = " << year << "年" << month << "月" << day << "日" << endl;
}
void output_date2(string s) {
	cout << "date2回调函数接口提示信息：" << s << endl;
}
void output_today(int year, int month, int day) {
	cout << year << "年" << month << "月" << day << "日" << endl;
}
void output_today(string s) {
	cout << "today回调函数接口提示信息：" << s << endl;
}

int main() {
	//system("chcp 65001");
	int year, month, day;
	while (1) {
		cout << "输入date1：";
		cin >> year >> month >> day;
		if (Date::isValid(year, month, day))break;// 调用静态函数接口
		cout << "请输入正确的日期。" << endl;
	}
	Date date1(year, month, day, output_date1, output_date1);
	while (1) {
		cout << "输入date2：";
		cin >> year >> month >> day;
		if (Date::isValid(year, month, day))break;// 调用静态函数接口
		cout << "请输入正确的日期。" << endl;
	}
	Date date2(year, month, day, output_date2, output_date2);
	while (1) {
		cout << "输入today：";
		cin >> year >> month >> day;
		if (Date::isValid(year, month, day))break;// 调用静态函数接口
		cout << "请输入正确的日期。" << endl;
	}
	Date today(year, month, day, output_today, output_today);

	today.showDate();
	today.setDate(0, 0, 0); today.showDate();// 带有合法性检查的set函数

	// 重载了运算符并可以链式调用
	today++++++++; today.showDate();
	((today += 6)+=3)+=7; today.showDate();
	((today+6)-9).showDate();
	
	today.getNextDay().getNextDay().getNextDay().showDate(); today.showDate();// 可链式调用的get函数
	date1.showDate();
	date2.showDate();
	cout << "date1 - date2 = " << date1 - date2 << endl;
	system("pause");
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
