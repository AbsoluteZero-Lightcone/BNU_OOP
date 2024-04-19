/**
  ******************************************************************************
  * @file    Triangle.h
  * @author  张亦法
  * @date    2024-04-19
  * @brief   Triangle class
  ******************************************************************************
  */
#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include <iostream>
using namespace std;
#include "util.h"
#include "Shape.h"
#include "Point.h"
#include <cmath>

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
		m_pointP1(0, 0),
		m_pointP2(0, 1),
		m_pointP3(1, 0)
	{}
	~Triangle() {}
	void Show()const {
		cout << "三角形"
			<< " " << m_pointP1.m_dX
			<< " " << m_pointP1.m_dY
			<< " " << m_pointP2.m_dX
			<< " " << m_pointP2.m_dY
			<< " " << m_pointP3.m_dX
			<< " " << m_pointP3.m_dY
			<< endl;
	}
	double Area()const {
		double a = getLength(m_pointP1, m_pointP2);
		double b = getLength(m_pointP2, m_pointP3);
		double c = getLength(m_pointP3, m_pointP1);
		double p = (a+b+c)/2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	double Perimeter()const {
		return
			getLength(m_pointP1, m_pointP2) +
			getLength(m_pointP2, m_pointP3) +
			getLength(m_pointP3, m_pointP1)
			;
	}
};
#endif // !__TRIANGLE_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
