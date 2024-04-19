/**
  ******************************************************************************
  * @file    Rectangle.h
  * @author  ’≈“‡∑®
  * @date    2024-04-19
  * @brief   Rectangle class
  ******************************************************************************
  */
#ifndef __RECTANGLE_H
#define __RECTANGLE_H
#include <iostream>
using namespace std;
#include <cmath>
#include "Shape.h"
#include "Point.h"

class Rectangle :public Shape {
private:
	Point m_pointLeftTop;
	Point m_pointRightBottom;

	void correct();
public:
	Rectangle();
	Rectangle(
		double t_dPointLeftTopX, double t_dPointLeftTopY,
		double t_dPointRightBottomX, double t_dPointRightBottomY
	);
	~Rectangle();
	Point getLeftTop()const;
	Point getRightBottom()const;
	void setRightBottom(const Point& t_pointRightBottom);
	void setLeftTop(const Point& t_pointLeftTop);
	void Show()const;
	double Area()const;
	double Perimeter()const;
};
#endif // !__RECTANGLE_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
