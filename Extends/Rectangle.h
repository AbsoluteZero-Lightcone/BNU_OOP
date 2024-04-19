/**
  ******************************************************************************
  * @file    Rectangle.h
  * @author  ’≈“‡∑®
  * @date    2024-04-19
  * @brief   Rectangle class
  ******************************************************************************
  */
#ifndef __RECTANGLE_H
#include <iostream>
using namespace std;
#include "util.h"

class Rectangle :public Shape {
private:
	Point m_pointLeftTop;
	Point m_pointRightBottom;

	void correct() {
		if (m_pointLeftTop.m_dY < m_pointRightBottom.m_dY){}
	}
public:
	Rectangle() :
		m_pointLeftTop(0, 1),
		m_pointRightBottom(1, 0) 
	{}
	Rectangle(
		double t_dPointLeftTopX, double t_dPointLeftTopY,
		double t_dPointRightBottomX, double t_dPointRightBottomY
	) :
		m_pointLeftTop(t_dPointLeftTopX, t_dPointLeftTopY),
		m_pointRightBottom(t_dPointRightBottomX, t_dPointRightBottomY)
	{}
	~Rectangle() {}
	void Show()const {
		cout << "æÿ–Œ" 
			<<" "<< m_pointLeftTop.m_dX
			<<" "<< m_pointLeftTop.m_dY
			<<" "<< m_pointRightBottom.m_dX
			<<" "<< m_pointRightBottom.m_dY
			<< endl;
	}
	double Area()const {
		return 
			(m_pointRightBottom.m_dX- m_pointLeftTop.m_dX)*
			(m_pointLeftTop.m_dY-m_pointRightBottom.m_dY);
	}
	double Perimeter()const {
		return
			((m_pointRightBottom.m_dX - m_pointLeftTop.m_dX) +
			(m_pointLeftTop.m_dY - m_pointRightBottom.m_dY))*2;
	}
};
#endif // !__RECTANGLE_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
