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

#define PI 3.14

class Circle :public Shape {
private:
	Point m_pointCenter;
	double m_dRadius;
public:
	Circle() :
		m_pointCenter(0, 0), m_dRadius(1.0) 
	{}
	Circle(Point t_pointCenter, double t_dRadius) :
		m_pointCenter(t_pointCenter), m_dRadius(t_dRadius)
	{}
	Circle(double t_dPointX, double t_dPointY, double t_dRadius) :
		m_pointCenter(t_dPointX, t_dPointY), m_dRadius(t_dRadius) 
	{}
	~Circle() {}
public:
	Point getCenter()const { return m_pointCenter; }
	double getRadius()const { return m_dRadius; }
	void setCenter(const Point& t_pointCenter) {
		this->m_pointCenter.m_dX = t_pointCenter.m_dX;
		this->m_pointCenter.m_dY = t_pointCenter.m_dY;
	}
	void setRadius(double t_dRadius) {
		this->m_dRadius = t_dRadius;
	}
public:
	void Show()const {
		cout << "" 
			<<" "<< m_pointCenter.m_dX 
			<<" "<< m_pointCenter.m_dY
			<<" "<< m_dRadius
			<< endl;
	}
	double Area() const {
		return PI * m_dRadius * m_dRadius ;
	}
	double Perimeter() const {
		return 2 * PI * m_dRadius ;
	}

};
#endif // !__CIRCLE_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
