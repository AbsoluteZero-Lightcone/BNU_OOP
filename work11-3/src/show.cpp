/**
  ******************************************************************************
  * @file    show.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.2.1
  * @date    2024-05-21
  * @brief   show
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ----------------------------------------------------------------- */
#include "show.h"

/* Exported variables ------------------------------------------------------- */
const string tests[] = {
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
	"|-12|",// todo 含语义的括号（绝对值）
	"12!",// todo 后置单目运算(阶乘运算)
	"E^(i*Pi)",// todo 数学常量
	"ans+1",// todo 记忆功能
};

const string cmds[] = {
	"exit",
	"test",
};
/* Exported functions ------------------------------------------------------- */
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

void show(const Expression& e) {
	cout << endl << "-- Calculating process ---------------------------------------------------------" << endl << endl;
	double res = Expression::Process(e);
	cout << endl << "------------------------------------------------------- Calculation completed --" << endl;
	cout << endl << ">>> " << e << " = " << res << endl << endl;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
