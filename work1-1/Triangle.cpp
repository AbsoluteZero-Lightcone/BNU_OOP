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
	m_dSide1(1),
	m_dSide2(1),
	m_dSide3(1)
{}

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
	if (t_dSide1 <= 0 || t_dSide2 <= 0 || t_dSide3 <= 0||!IsTriangle())
		throw "can't consturct Triangle!";
	m_dSide1 = t_dSide1;
	m_dSide2 = t_dSide2;
	m_dSide3 = t_dSide3;
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief 判定是否构成三角形函数IsTriangle
  */
bool Triangle::IsTriangle()const {
	if (m_dSide1 + m_dSide2 <= m_dSide3)return false;
	if (m_dSide2 + m_dSide3 <= m_dSide1)return false;
	if (m_dSide3 + m_dSide1 <= m_dSide2)return false;
	return true;
}

/**
  * @brief 判定是否是等边三角形函数Equilateral
  */
bool Triangle::Equilateral()const {
	if (!IsTriangle())return false;
	if (m_dSide1 != m_dSide2)return false;
	if (m_dSide2 != m_dSide3)return false;
	if (m_dSide3 != m_dSide1)return false;
	return true;
}

/**
  * @brief 判定是否是等腰三角形函数Isosceles
  */
bool Triangle::Isosceles()const {
	if (!IsTriangle())return false;
	if (m_dSide1 == m_dSide2 || m_dSide1 == m_dSide3)return true;
	if (m_dSide2 == m_dSide3 || m_dSide2 == m_dSide1)return true;
	if (m_dSide3 == m_dSide1 || m_dSide3 == m_dSide2)return true;
	return false;
}

/**
  * @brief 判定是否是直角三角形函数RightTriangle
  */
bool Triangle::RightTriangle()const {
	if (!IsTriangle())return false;
	if (pow(m_dSide1, 2) + pow(m_dSide2, 2) - pow(m_dSide3, 2) < DBL_EPSILON)return true;
	if (pow(m_dSide2, 2) + pow(m_dSide3, 2) - pow(m_dSide1, 2) < DBL_EPSILON)return true;
	if (pow(m_dSide3, 2) + pow(m_dSide1, 2) - pow(m_dSide2, 2) < DBL_EPSILON)return true;
	return false;
}

/**
  * @brief 计算面积函数Area
  */
double Triangle::Area()const {
	double p = (m_dSide1 + m_dSide2 + m_dSide3) / 2;
	return sqrt(p * (p - m_dSide1) * (p - m_dSide2) * (p - m_dSide3));
}

/**
  * @brief 计算周长函数Perimeter
  */
double Triangle::Perimeter()const {
	return m_dSide1 + m_dSide2 + m_dSide3;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const exported_class& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Triangle& source) {
	out
		<< "It " << (source.Equilateral()   ? "is" : "isn't") << " an equilateral triangle." << endl
		<< "It " << (source.Isosceles()     ? "is" : "isn't") << " an isosceles triangle." << endl
		<< "It " << (source.RightTriangle() ? "is" : "isn't") << " a right triangle." << endl
		<< "area = " << source.Area() << endl
		<< "perimeter = " << source.Perimeter() << endl;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
