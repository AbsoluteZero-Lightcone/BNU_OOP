/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-13
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;
#include "IntArray.h"

#define LENGTH1 10
#define LENGTH2 20

int main() {
	IntArray arr1(LENGTH1);
	cout << "arr1 请输入" << LENGTH1 << "个整数：" << endl;
	cin >> arr1;
	IntArray arr2(arr1);
	IntArray arr3(LENGTH2);
	arr3 = arr1;
	cout << "arr1 = " << arr1 << endl;
	cout << "arr2 = " << arr2 << endl;
	cout << "arr3 = " << arr3 << endl;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
