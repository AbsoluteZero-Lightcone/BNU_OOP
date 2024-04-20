/**
  ******************************************************************************
  * @file    Circle.h
  * @author  ÕÅÒà·¨ 202311998186
  * @date    2024-04-19
  * @brief   Circle class
  ******************************************************************************
  */
#include "Circle.h"

Circle::Circle() :
	m_pointCenter(0, 0), m_dRadius(1.0)
{}
Circle::Circle(Point t_pointCenter, double t_dRadius) :
	m_pointCenter(t_pointCenter), m_dRadius(t_dRadius)
{}
Circle::Circle(double t_dPointX, double t_dPointY, double t_dRadius) :
	m_pointCenter(t_dPointX, t_dPointY), m_dRadius(t_dRadius)
{}
Circle::~Circle() {}
Point Circle::getCenter()const { return m_pointCenter; }
double Circle::getRadius()const { return m_dRadius; }
void Circle::setCenter(const Point& t_pointCenter) {
	this->m_pointCenter.m_dX = t_pointCenter.m_dX;
	this->m_pointCenter.m_dY = t_pointCenter.m_dY;
}
void Circle::setRadius(double t_dRadius) {
	this->m_dRadius = t_dRadius;
}
void Circle::Show()const {
	cout << "Ô²"
		<< " " << m_pointCenter.m_dX
		<< " " << m_pointCenter.m_dY
		<< " " << m_dRadius
		<< endl;
}
double Circle::Area() const {
	return PI * m_dRadius * m_dRadius;
}
double Circle::Perimeter() const {
	return 2 * PI * m_dRadius;
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
