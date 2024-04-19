/**
  ******************************************************************************
  * @file    Triangle.h
  * @author  ’≈“‡∑®
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
	);
	Triangle();
	~Triangle();
	void Show()const;
	double Area()const;
	double Perimeter()const;
	Point getP1()const;
	Point getP2()const;
	Point getP3()const;
	void setP1(const Point& t_pointP1);
	void setP2(const Point& t_pointP2);
	void setP3(const Point& t_pointP3);
};
#endif // !__TRIANGLE_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
