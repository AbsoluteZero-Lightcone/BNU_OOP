/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;

#include "Student.h"
#include "Teacher.h"

int main() {
	Student* stuArr;
	Teacher* teaArr;
	cout << "您需要建立几位学生(M)和几位教师(N)：" ;
	int m, n;
	cin >> m >> n;
	stuArr = new Student[m];
	teaArr = new Teacher[n];
	string name;
	cout << "请输入5位学生的姓名：";
	for (int i = 0; i < m; i++){
		cin >> name;
		stuArr[i].set_strName(name);
	}
	cout << "请输入3位教师的姓名：";
	for (int i = 0; i < n; i++){
		cin >> name;
		teaArr[i].set_strName(name);
	}

	delete[] stuArr;
	delete[] teaArr;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
