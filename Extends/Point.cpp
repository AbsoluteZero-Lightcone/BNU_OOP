/**
  ******************************************************************************
  * @file    Point.cpp
  * @author  ’≈“‡∑®
  * @date    2024-04-19
  * @brief   Point class
  ******************************************************************************
  */
#include "Point.h"

Point::Point() :m_dX(0.0), m_dY(0.0) {}
Point::Point(double t_dX, double t_dY) :m_dX(t_dX), m_dY(t_dY) {}
Point::Point(const Point& t_pointP) :m_dX(t_pointP.m_dX), m_dY(t_pointP.m_dY) {}
Point::~Point() {}

double Point::getX()const { return m_dX; }
double Point::getY()const { return m_dY; }
void Point::setX(double t_dX) {
	m_dX = t_dX;
}
void Point::setY(double t_dY) {
	m_dY = t_dY;
}
void Point::Show()const {
	cout << "µ„"
		<< " " << m_dX
		<< " " << m_dY
		<< endl;
}
double Point::Area()const {
	return 0;
}
double Point::Perimeter()const {
	return 0;
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
