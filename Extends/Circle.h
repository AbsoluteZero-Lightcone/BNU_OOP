/**
  ******************************************************************************
  * @file    Circle.h
  * @author  ’≈“‡∑®
  * @date    2024-04-19
  * @brief   Circle class
  ******************************************************************************
  */
#ifndef __CIRCLE_H
#define __CIRCLE_H
#include <iostream>
using namespace std;
#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle :public Shape {
private:
	Point m_pointCenter;
	double m_dRadius;
public:
	Circle();
	Circle(Point t_pointCenter, double t_dRadius);
	Circle(double t_dPointX, double t_dPointY, double t_dRadius);
	~Circle();
public:
	Point getCenter()const;
	double getRadius()const;
	void setCenter(const Point& t_pointCenter);
	void setRadius(double t_dRadius);
public:
	void Show()const;
	double Area() const;
	double Perimeter() const;
};
#endif // !__CIRCLE_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
