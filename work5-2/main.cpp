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
	cout << "����Ҫ������λѧ��(M)�ͼ�λ��ʦ(N)��" ;
	int m, n;
	cin >> m >> n;
	stuArr = new Student[m];
	teaArr = new Teacher[n];
	string name;
	cout << "������5λѧ����������";
	for (int i = 0; i < m; i++){
		cin >> name;
		stuArr[i].set_strName(name);
	}
	cout << "������3λ��ʦ��������";
	for (int i = 0; i < n; i++){
		cin >> name;
		teaArr[i].set_strName(name);
	}

	delete[] stuArr;
	delete[] teaArr;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
