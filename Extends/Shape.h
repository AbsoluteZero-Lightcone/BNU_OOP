#ifndef __SHAPE_H

#include <iostream>
using namespace std;
class Shape
{
public:
	void GetInfo() const {
		cout << "����һ��";
		Show();
		cout << endl << "���������" << Area();
		cout << endl << "�����ܳ���" << Perimeter();
	}
	virtual void Show()const = 0;
	virtual double Area()const = 0;
	virtual double Perimeter()const = 0;

};

#endif // !__SHAPE_H
