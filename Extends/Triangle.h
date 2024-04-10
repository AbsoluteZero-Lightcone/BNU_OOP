#ifndef __TRIANGLE_H

#include "Shape.h"
#include <iostream>
using namespace std;


class Triangle : public Shape {
private:
	double m_nX;
	double m_nY;
public:
	void Show()const {
		cout << "" << endl;
	}
	double Area() const {
		cout <<  << endl;
	}
	double Perimeter() const {
		cout << 0 << endl;
	}
};
#endif // !__TRIANGLE_H
