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

// todo ���ܴ����� -1+2 �� 1+(-2)
// todo ���ܴ���˺�ʡ�Ե���� 2(3+4) �� (3+4)2

int main() {
	string s1 = "1 + 2.1 * 3 /2.12*1-6";
	string s2 = "1 + 2.15 * 3 / (2.12*(1-6))+2.1 * (3 /2.12)*1-6";
	Expression e;

	double res = Expression::Calculate(e);
	cout << e << " = "<< res << endl;
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
