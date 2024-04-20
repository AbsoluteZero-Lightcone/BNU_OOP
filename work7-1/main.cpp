/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;
#include "Persons.h"
int main() {
	cout << "Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: " << endl;

	char mode;
	cin >> mode;

	string t_strName;        int t_nAge;
	string t_strMajor;       string t_strStudentID;
	string t_strDepartment;  string t_strEmployeeID;

	bool isOver = 0;
	while (!isOver)
	switch (mode) {
	case 'p': {// 花括号限制变量的作用域（cppreference: switch statement）
		cout << "Input person name :" << endl;
		cin >> t_strName;
		cout << "Input person age :" << endl;
		cin >> t_nAge;
		Person p(t_strName, t_nAge);
		cout << p.get_strName() << " " << p.get_nAge() << endl;
		break;
	}
	case 's': {
		break;
	}
	case 'e':
	{
		break;
	}
	case 'v':
	{
		cout << "Input stuEmployee name :" << endl;
		cin >> t_strName;
		cout << "Input stuEmployee age :" << endl;
		cin >> t_nAge;
		cout << "Input stuEmployee major :" << endl;
		cin >> t_strMajor;
		cout << "Input stuEmployee student id :" << endl;
		cin >> t_strStudentID;
		cout << "Input stuEmployee department :" << endl;
		cin >> t_strDepartment;
		cout << "Input stuEmployee employee id :" << endl;
		cin >> t_strEmployeeID;

		StuEmployee p(t_strName, t_nAge, t_strMajor, t_strStudentID,t_strDepartment, t_strEmployeeID);

		cout 
			<< p.get_strName() << " " 
			<< p.get_nAge() << " "
			<< p.get_strMajor() << " "
			<< p.get_strStudentID() << " "
			<< p.get_strDepartment() << " "
			<< p.get_strEmployeeID() 
			<< endl;
		
		break;
	}
	case 'o':
		cout << "Byebye~" << endl;
		isOver = 1;
		break;
	default:
		break;
	}

	return 0;
}
/*
* 样例：
Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: p
Input person name: 王伟
Input person age: 40
王伟 40
Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: s
Input student name: 刘红
Input student age: 20
Input student major: computer
Input student id: 202010000001
刘红 20 computer 202010000001
Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: e
Input employee name: 李凯
Input employee age: 30
Input employee department: ScienceDept.
Input employee id: 19980055
李凯 30 ScienceDept. 19980055
Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: v
Input stuEmployee name: 赵成
Input stuEmployee age: 23
Input stuEmployee major: AI
Input stuEmployee student id: 201830000005
Input stuEmployee department: TeachingAffairDept.
Input stEemployee employee id: 20231108
赵成 23 AI 201830000005 TeachingAffairDept. 20231108
Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: o
Byebye~

*/
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
