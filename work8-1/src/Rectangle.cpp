/**
  ******************************************************************************
  * @file    Rectangle.cpp
  * @author  ’≈“‡∑®
  * @date    2024-04-19
  * @brief   Rectangle class
  ******************************************************************************
  */

#include "Rectangle.h"

void Rectangle::correct() {
	if (m_pointLeftTop.m_dY < m_pointRightBottom.m_dY) {}
}
Rectangle::Rectangle() :
	m_pointLeftTop(0, 1),
	m_pointRightBottom(1, 0)
{}
Rectangle::Rectangle(
	double t_dPointLeftTopX, double t_dPointLeftTopY,
	double t_dPointRightBottomX, double t_dPointRightBottomY
) :
	m_pointLeftTop(t_dPointLeftTopX, t_dPointLeftTopY),
	m_pointRightBottom(t_dPointRightBottomX, t_dPointRightBottomY)
{}
Rectangle::~Rectangle() {}
void Rectangle::Show()const {
	cout << "æÿ–Œ"
		<< " " << m_pointLeftTop.m_dX
		<< " " << m_pointLeftTop.m_dY
		<< " " << m_pointRightBottom.m_dX
		<< " " << m_pointRightBottom.m_dY
		<< endl;
}
double Rectangle::Area()const {
	return
		abs(m_pointRightBottom.m_dX - m_pointLeftTop.m_dX) *
		abs(m_pointLeftTop.m_dY - m_pointRightBottom.m_dY);
}
double Rectangle::Perimeter()const {
	return (
		abs(m_pointRightBottom.m_dX - m_pointLeftTop.m_dX) +
		abs(m_pointLeftTop.m_dY - m_pointRightBottom.m_dY)
		) * 2;
}


Point Rectangle::getLeftTop()const {
	return m_pointLeftTop;
}
Point Rectangle::getRightBottom()const {
	return m_pointRightBottom;
}
void Rectangle::setRightBottom(const Point& t_pointRightBottom) {
	m_pointLeftTop.m_dX = t_pointRightBottom.m_dX;
	m_pointLeftTop.m_dY = t_pointRightBottom.m_dY;
}
void Rectangle::setLeftTop(const Point& t_pointLeftTop) {
	m_pointRightBottom.m_dX = t_pointLeftTop.m_dX;
	m_pointRightBottom.m_dY = t_pointLeftTop.m_dY;
}
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
