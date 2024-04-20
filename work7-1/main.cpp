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

int main() {
	cout << "Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: " << endl;
	char mode;
	cin >> mode;
	while (1);
	switch (mode) {
	case 'p':
		break;
	case 's':
		break;
	case 'e':
		break;
	case 'v':
		break;
	case 'o':
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
