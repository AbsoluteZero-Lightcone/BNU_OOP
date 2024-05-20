/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.3.0
  * @date    2024-05-16
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;

#include "Expression.h"

string tests[] = {
	// verified functions:
	"1 + (2.15) * 3 / (2.120001*(1-6))+2.1 * (3 /2.12)*1-6",// 一般的表达式
	"123",// 处理纯数字
	"((((()))))" ,// 判断空括号
	"-1+2",
	"1+(-2)",// 处理负号 -1+2 和 1+(-2)
	"1/(2-2)"// 除零检查
	"2(3+4)",// 乘号省略的情况非法 2(3+4)
	"2^3",// 幂运算支持
	"2%3",// 浮点取余运算fmod支持

	// todos:
	"1++++----2",// todo 检查不合法的连续加减号
	"sin(123)",// todo 函数式运算支持
	"|-12|",// todo 特殊括号（绝对值）
	"12!",// todo 后置单目运算(阶乘运算)
	"E^(i*Pi)",// todo 数学常量
	"ans+1",// todo 记忆功能
};

template<class T, unsigned N>
void test(T(&tests)[N]) {
	for (int i = 0; i < N; i++) {
		cout << "Test " << i << ": " << tests[i] << endl;
		try {
			Expression e(tests[i]);
#ifdef ENABLE_PROCESS_PRINT
			cout << "[Calculating process]" << endl;
#endif
			cout << endl << ">>> " << e << " = " << Expression::Calculate(e) << endl << endl;
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	}

}

int main() {
	test(tests);
	cout << "Supported operators: + - * / ^ %" << endl;
	do {
		try {
			string s;
			cout << "Input an expression: " << endl << ">>> ";
			cin >> s;
			Expression e(s);
#ifdef ENABLE_PROCESS_PRINT
			cout << " [Calculating process]" << endl;
#endif
			double res = Expression::Calculate(e);
			cout << endl << ">>> " << e << " = " << res << endl << endl;
		}
		catch (const char* err) {
			cerr << endl << "[Error] " << err << endl << endl;
		}
	} while (true);
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
