/**
  ******************************************************************************
  * @file    Point.h
  * @author  ’≈“‡∑®
  * @date    2024-04-19
  * @brief   Point class
  ******************************************************************************
  */
#ifndef __POINT_H
#define __POINT_H

#include <iostream>
using namespace std;
#include "Shape.h"

class Point :public Shape {
private:
	double m_dX;
	double m_dY;
public:
	Point();
	Point(double t_dX, double t_dY);
	Point(const Point& t_pointP);
	~Point();
	double getX()const;
	double getY()const;
	void setX(double t_dX);
	void setY(double t_dY);
	void Show()const;
	double Area()const;
	double Perimeter()const;
	friend class Circle;
	friend class Triangle;
	friend class Rectangle;
	friend double getLength(const Point& p1, const Point& p2);
};
#endif // !__POINT_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
