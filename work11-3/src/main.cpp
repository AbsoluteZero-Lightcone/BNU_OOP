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

int main() {
	string s = "1 + 2.15 * 3 / (2.12*(1-6))";
	Expression e(s);
	cout << e << endl;
	return 0;
}

template<class T>
void printArray(T* arr, unsigned N) {
	cout << "{";
	for (int i = 0; i < N; i++) {
		if (i)cout << ",";
		cout << arr[i];
	}
	cout << "}";
	cout << endl;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
