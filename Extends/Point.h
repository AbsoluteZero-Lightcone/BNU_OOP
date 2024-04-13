#ifndef __POINT_H
#include <iostream>
using namespace std;

class Point :public Shape {
private:
	double m_dX;
	double m_dY;
public:
	Point() :m_dX(0.0), m_dY(0.0) {}
	Point(double t_dX, double t_dY) :m_dX(t_dX), m_dY(t_dY) {}
	Point(const Point& t_pointP) :m_dX(t_pointP.m_dX), m_dY(t_pointP.m_dY) {}
	~Point() {}
public:
	double getX()const { return m_dX; }
	double getY()const { return m_dY; }
	void setX(double t_dX) {
		m_dX = t_dX;
	}
	void setY(double t_dY) {
		m_dY = t_dY;
	}
	void Show()const {
		cout << "µã" << endl;
	}
	double Area()const {
		return 0;
	}
	double Perimeter()const {
		return 0;
	}
	friend class Circle;
	friend class Triangle;
	friend class Rectangle;

};
#endif // !__POINT_H
