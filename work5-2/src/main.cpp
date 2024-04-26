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
	throw "û���ҵ���ʦ��";
}

int findStudent(string name, const Student* const arr, int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i].get_strName() == name)return i;
	}
	throw "û���ҵ�ѧ����";
}


bool isContinue() {
	string command;
	cout << "��Ҫ������(Y/N): ";
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
	cout << "����Ҫ������λѧ��(M)�ͼ�λ��ʦ(N)��";
	int stuCount, teaCount;
	cin >> stuCount >> teaCount;
	stuArr = new Student[stuCount];
	teaArr = new Teacher[teaCount];

	string name;
	cout << "������"<< stuCount <<"λѧ����������";
	for (int i = 0; i < stuCount; i++) {
		cin >> name;
		stuArr[i].set_strName(name);
	}
	cout << "������"<< teaCount <<"λ��ʦ��������";
	for (int i = 0; i < teaCount; i++) {
		cin >> name;
		teaArr[i].set_strName(name);
	}

	do {
		int index;

		while (1) {
			cout << "��ѡ��һλ��ʦ: ";
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
			cout << "��ѡ��һλѧ����";
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

		cout << "������Ҫ���ӵ�ѧ�֣�";
		cin >> n;
		curTeacher.setStudentCredit(curStudent, n);
		cout << "��ʦ" << curTeacher.get_strName() << "��ѧ��" << curStudent.get_strName()
			<< "����" << curStudent.get_nCredit() << "ѧ�֣������ɹ���" << endl;

		cout << "������Ҫ���ӵ��ܳɼ���";
		cin >> n;
		curTeacher.setStudentScore(curStudent, n);
		cout << "��ʦ" << curTeacher.get_strName() << "��ѧ��" << curStudent.get_strName()
			<< "�����ܳɼ�" << curStudent.get_nCredit() << "�������ɹ���" << endl;
	} while (isContinue());

	cout << "ѧ����Ϣ��" << endl;
	cout << "����\t��ѧ��\t�ܳɼ�" << endl;
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
