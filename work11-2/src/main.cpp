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
#include "Stack.h"

int main() {
	Stack<int> s1;
	Stack<int> s2 = s1.push(1).push(2).push(3);
	int a1 = s2.pop();
	int a2 = s2.pop();
	s1 << 1 << 2 << 3;
	cout << s1 << endl;
	int a, b, c;
	s1 >> a >> b >> c;
	cout << a << b << c << endl;
	cout << s1 << endl;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
