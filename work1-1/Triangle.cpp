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

/**
  * @brief 设置边长函数SetLen ，给3条边长赋值
  */
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

/**
  * @brief 判定是否构成三角形函数IsTriangle
  */
bool Triangle::IsTriangle() {
	if (m_dSide1 + m_dSide2 <= m_dSide3)return false;
	if (m_dSide2 + m_dSide3 <= m_dSide1)return false;
	if (m_dSide3 + m_dSide1 <= m_dSide2)return false;
	return true;
}

/**
  * @brief 判定是否是等边三角形函数Equilateral
  */
bool Triangle::Equilateral() {
	if (!IsTriangle())return false;
	if (m_dSide1 != m_dSide2)return false;
	if (m_dSide2 != m_dSide3)return false;
	if (m_dSide3 != m_dSide1)return false;
	return true;
}

/**
  * @brief 判定是否是等腰三角形函数Isosceles
  */
bool Triangle::Isosceles() {
	if (!IsTriangle())return false;
	if (m_dSide1 == m_dSide2 || m_dSide1 == m_dSide3)return true;
	if (m_dSide2 == m_dSide3 || m_dSide2 == m_dSide1)return true;
	if (m_dSide3 == m_dSide1 || m_dSide3 == m_dSide2)return true;
	return false;
}

/**
  * @brief 判定是否是直角三角形函数RightTriangle
  */
bool Triangle::RightTriangle() {
	if (!IsTriangle())return false;
	if (pow(m_dSide1, 2) + pow(m_dSide2, 2) - pow(m_dSide3, 2) < DBL_EPSILON)return true;
	if (pow(m_dSide2, 2) + pow(m_dSide3, 2) - pow(m_dSide1, 2) < DBL_EPSILON)return true;
	if (pow(m_dSide3, 2) + pow(m_dSide1, 2) - pow(m_dSide2, 2) < DBL_EPSILON)return true;
	return false;
}

/**
  * @brief 计算面积函数Area
  */
double Triangle::Area() {
	double p = (m_dSide1 + m_dSide2 + m_dSide3) / 2;
	return sqrt(p * (p - m_dSide1) * (p - m_dSide2) * (p - m_dSide3));
}

/**
  * @brief 计算周长函数Perimeter
  */
double Triangle::Perimeter() {
	return m_dSide1 + m_dSide2 + m_dSide3;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
