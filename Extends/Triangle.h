#ifndef __TRIANGLE_H

#include "Shape.h"
#include <iostream>
using namespace std;


class Triangle : public Shape {
private:
	Point m_pointP1;
	Point m_pointP2;
	Point m_pointP3;
public:
	Triangle(
		double t_dPoint1X, double t_dPoint1Y,
		double t_dPoint2X, double t_dPoint2Y,
		double t_dPoint3X, double t_dPoint3Y
	) : 
		m_pointP1(t_dPoint1X, t_dPoint1Y),
		m_pointP2(t_dPoint2X, t_dPoint2Y),
		m_pointP3(t_dPoint3X, t_dPoint3Y) 
	{}
	Triangle() : 
		m_pointP1(0,0), 
		m_pointP2(0,1), 
		m_pointP3(1,0) 
	{}
	
	void Show()const {
		cout << "" << endl;
	}
	double Area() const {
		cout << 0 << endl;
	}
	double Perimeter() const {
		cout << 0 << endl;
	}
};
#endif // !__TRIANGLE_H
