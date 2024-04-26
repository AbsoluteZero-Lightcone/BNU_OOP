/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.2.0
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


int findTeacher(string name, const Teacher* const arr, int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i].get_strName() == name)return i;
	}
	throw "没有找到教师！";
}

int findStudent(string name, const Student* const arr, int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i].get_strName() == name)return i;
	}
	throw "没有找到学生！";
}


bool isContinue() {
	string command;
	cout << "还要继续吗？(Y/N): ";
	cin >> command;
	if (command == "y" || command == "Y")
		return 1;
	else if (command == "n" || command == "N")
		return 0;
	else {
		cerr << "Invalid command." << endl;
		return isContinue();
	}
}

int main() {
	Student* stuArr;
	Teacher* teaArr;
	cout << "您需要建立几位学生(M)和几位教师(N)：";
	int stuCount, teaCount;
	cin >> stuCount >> teaCount;
	stuArr = new Student[stuCount];
	teaArr = new Teacher[teaCount];

	string name;
	cout << "请输入"<< stuCount <<"位学生的姓名：";
	for (int i = 0; i < stuCount; i++) {
		cin >> name;
		stuArr[i].set_strName(name);
	}
	cout << "请输入"<< teaCount <<"位教师的姓名：";
	for (int i = 0; i < teaCount; i++) {
		cin >> name;
		teaArr[i].set_strName(name);
	}

	do {
		int index;

		while (1) {
			cout << "请选择一位教师: ";
			cin >> name;
			try {
				index = findTeacher(name, teaArr, teaCount);
				break;
			}
			catch (const char* err) {
				cout << err << endl;
				continue;
			}
		}
		Teacher& curTeacher = teaArr[index];

		while (1) {
			cout << "请选择一位学生：";
			cin >> name;
			try {
				index = findStudent(name, stuArr, stuCount);
				break;
			}
			catch (const char* err) {
				cout << err << endl;
				continue;
			}
		}
		Student& curStudent = stuArr[index];

		int n;

		cout << "请输入要增加的学分：";
		cin >> n;
		curTeacher.setStudentCredit(curStudent, n);
		cout << "教师" << curTeacher.get_strName() << "给学生" << curStudent.get_strName()
			<< "增加" << curStudent.get_nCredit() << "学分，操作成功。" << endl;

		cout << "请输入要增加的总成绩：";
		cin >> n;
		curTeacher.setStudentScore(curStudent, n);
		cout << "教师" << curTeacher.get_strName() << "给学生" << curStudent.get_strName()
			<< "增加总成绩" << curStudent.get_nCredit() << "，操作成功。" << endl;
	} while (isContinue());

	cout << "学生信息：" << endl;
	cout << "姓名\t总学分\t总成绩" << endl;
	for (int i = 0; i < stuCount; i++) {
		cout << stuArr[i].get_strName() << "\t"
			<< stuArr[i].get_nCredit() << "\t"
			<< stuArr[i].get_nScore() << endl;
	}

	if (stuArr != nullptr)delete[] stuArr, stuArr = nullptr;
	if (teaArr != nullptr)delete[] teaArr, teaArr = nullptr;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
