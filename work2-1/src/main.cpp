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

int main() {
	Student stu1[10];
	cout << "stu1��10��ͬѧ����Ϣ��" << endl;
	for (int i = 0; i < 10; i++) {
		cout << stu1[i];
	}

	Student stu2[10] = {
		Student("����","202010000005",'m',90),
		Student("����","201810200012",'m',85),
		Student("����","202010020108",'m',76),
		Student("������","201910060022",'f',92),
		Student("����ƽ","202010000115",'m',88),
		Student("�Ŵ���","200610000059",'m',82),
		Student("���¸�","201110040001",'m',77),
		Student("����","201810080072",'f',89),
		Student("����","202010000023",'f',90),
		Student("��ƽƽ","202010000007",'f',93)
	};
	cout << "stu2��10��ͬѧ����Ϣ��" << endl;
	for (int i = 0; i < 10; i++) {
		cout << stu2[i];
	}
	cout << "������ߵ�ͬѧ��Ϣ��" << endl;
	cout << MaxScore(stu2,10);
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
