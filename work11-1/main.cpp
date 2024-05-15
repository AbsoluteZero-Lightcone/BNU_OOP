/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-15
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

int main() {
	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };    //分别查找0, 4
	char b[] = "Beijing Normal University";  //分别查找 字符‘m’ ‘i’  ‘z’
	string c[] = { "BNU","welcome","Beijing","abc","1234" }; //分别查找"ok"  "abc"
	Person d[] = {
		Person("wangwei",20),
		Person("liuli",30),
		Person("zhangsan",40),
		Person("zhaoming",20)
	};	//分别查找Person（"liuli", 30）, Person（"liuli", 20）

	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
