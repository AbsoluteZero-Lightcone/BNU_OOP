#include "Shape.h"


#include <iostream>
using namespace std;


void Shape::GetInfo() const {
	cout << "����һ��";
	Show();
	cout << endl << "���������" << Area();
	cout << endl << "�����ܳ���" << Perimeter();
}