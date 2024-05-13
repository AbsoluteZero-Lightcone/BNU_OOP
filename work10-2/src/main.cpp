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
#include <fstream>
using namespace std;
#include "Student.h"

#define LENGTH 10

int main() {
	Student* arr[LENGTH];
	ifstream infile(".\\res\\in.txt");
	if (!infile.is_open()) {
		cerr << "文件打开失败" << endl;
		return 1;
	}
	for (int i = 0; i < LENGTH; i++) {
		string name, id;
		double chinese, math, english;
		infile >> name >> id >> chinese >> math >> english;
		arr[i] = new Student(name, id, chinese, math, english);
	}
	infile.close();
	Student::sort(arr, LENGTH);
	cout << "排序后：" << endl;
	cout << "姓名\t学号\t\t语文\t数学\t英语\t总分" << endl;
	for (int i = 0; i < LENGTH; i++) {
		cout << *arr[i] << endl;
	}
	for (int i = 0; i < LENGTH; i++) {
		delete arr[i];
	}
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
