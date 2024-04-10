#ifndef __RECTANGLE_H

#include "Shape.h"
#include <iostream>
using namespace std;

class Rectangle :public Shape {
private:
	Point m_pointLeftTop;
	Point m_pointRightBottom;
public:
	Rectangle() :m_pointLeftTop(0, 0), m_pointRightBottom(0, 0) {

	}
	void Show()const {
		cout << "¾ØÐÎ" << endl;
	}
	double Area()const {
		cout << 0 << endl;
	}
	double Perimeter()const {
		cout << 0 << endl;
	}
};
#endif // !__RECTANGLE_H
