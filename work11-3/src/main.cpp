/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-16
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;
#include "Expression.h"

// todo 重载表达式的算数运算符

string test[] = {
	"1 + (2.15) * 3 / (2.12*(1-6))+2.1 * (3 /2.12)*1-6",// 一般的表达式
	"123",// 处理纯数字
	"((((()))))" ,// 判断空括号
	"-1+2",
	"1+(-2)",// 处理负号 -1+2 和 1+(-2)
	"2(3+4)"// 乘号省略的情况非法 2(3+4)
};


int main() {
	do {
		try {
			string s;
			cout << "Input an expression: ";
			cin >> s;
			Expression e(s);
			cout << "Calculating process: " << endl;
			double res = Expression::Calculate(e);
			cout << endl << e << " = " << res << endl << endl;
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	} while (true);
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
