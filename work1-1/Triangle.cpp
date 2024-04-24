/**
  ******************************************************************************
  * @file    Triangle.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Triangle class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Triangle.h"

/* Constructors & Deconstructor --------------------------------------------- */
Triangle::Triangle() :
	m_dSide1(0),
	m_dSide2(0),
	m_dSide3(0)
{}

Triangle::Triangle(
	double t_dSide1,
	double t_dSide2,
	double t_dSide3
) :
	m_dSide1(t_dSide1),
	m_dSide2(t_dSide2),
	m_dSide3(t_dSide3)
{}

Triangle::~Triangle() {}

/* Getters & Setters -------------------------------------------------------- */
double Triangle::get_dSide1()const { return m_dSide1; }
double Triangle::get_dSide2()const { return m_dSide2; }
double Triangle::get_dSide3()const { return m_dSide3; }
void Triangle::set_dSide1(double t_dSide1) { m_dSide1 = t_dSide1; }
void Triangle::set_dSide2(double t_dSide2) { m_dSide2 = t_dSide2; }
void Triangle::set_dSide3(double t_dSide3) { m_dSide3 = t_dSide3; }

void Triangle::SetLen(double t_dSide1, double t_dSide2, double t_dSide3) {
	if (t_dSide1 <= 0 || t_dSide2 <= 0 || t_dSide3 <= 0) {
		cerr << "边长不能是负数或零" << endl;
		return;
	}
	m_dSide1 = t_dSide1;
	m_dSide2 = t_dSide2;
	m_dSide3 = t_dSide3;
}

/* Exported functions ------------------------------------------------------- */

bool Triangle::IsTriangle(){
	if (m_dSide1 + m_dSide2 <= m_dSide3)return false;
	if (m_dSide2 + m_dSide3 <= m_dSide1)return false;
	if (m_dSide3 + m_dSide1 <= m_dSide2)return false;
	return true;
}

bool Triangle::Equilateral(){
	if (!IsTriangle())return false;
}
bool Triangle::Isosceles(){
	if (!IsTriangle())return false;
}
bool Triangle::RightTriangle(){
	if (!IsTriangle())return false;
}
double Triangle::Area(){}
double Triangle::Perimeter() {}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
