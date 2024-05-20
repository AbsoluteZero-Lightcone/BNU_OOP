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

// todo 不能处理负号 -1+2 和 1+(-2)
// todo 不能处理乘号省略的情况 2(3+4)
// todo 重载表达式的算数运算符

int main() {
	Expression e;
	e = "1 + (2.15) * 3 / (2.12*(1-6))+2.1 * (3 /2.12)*1-6";
	double res = Expression::Calculate(e);
	cout << e << " = " << res << endl;
	do {
		try {
			string s;
			cout << "Input an expression: ";
			cin >> s;
			Expression e(s);
			double res = Expression::Calculate(e);
			cout << e << " = " << res << endl;
		}
		catch (const char* err) {
			cout << err << endl;
		}
	} while (true);
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
