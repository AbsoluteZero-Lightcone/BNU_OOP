/**
  ******************************************************************************
  * @file    Rectangle.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Rectangle class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Rectangle.h"

/* Constructors & Deconstructor --------------------------------------------- */
Rectangle::Rectangle() :
	m_pointCenter(0,0),
	m_dWidth(1),
	m_dHeight(1)
{}

Rectangle::Rectangle(Point t_pointCenter, double t_dWidth,double t_dHeight) :
	m_pointCenter(t_pointCenter),
	m_dWidth(t_dWidth),
	m_dHeight(t_dHeight)
{}

Rectangle::Rectangle(const Rectangle& source) :
	m_pointCenter(source.m_pointCenter),
	m_dWidth(source.m_dWidth),
	m_dHeight(source.m_dHeight)
{}

Rectangle::~Rectangle() {}

/* Getters & Setters -------------------------------------------------------- */
Point Rectangle::get_pointCenter()const { return m_pointCenter; }
void Rectangle::set_pointCenter(Point t_pointCenter) { m_pointCenter = t_pointCenter; }
double Rectangle::get_dWidth()const { return m_dWidth; }
void Rectangle::set_dWidth(double t_dWidth) { m_dWidth = t_dWidth; }
double Rectangle::get_dHeight()const { return m_dHeight; }
void Rectangle::set_dHeight(double t_dHeight) { m_dHeight = t_dHeight; }

/* Private functions -------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Rectangle& source : 待赋的值
  * @retval 无
  */
void Rectangle::operator=(const Rectangle& source) {
	m_pointCenter = source.m_pointCenter;
	m_dWidth = source.m_dWidth;
	m_dHeight = source.m_dHeight;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Rectangle& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Rectangle& source) {
	// todo
	return out;
}

/**
  * @brief 重载等于运算符
  * @param const Rectangle& n1 : 运算符左边的值
  * @param const Rectangle& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Rectangle& n1, const Rectangle& n2) {
	if (n1.m_pointCenter != n2.m_pointCenter)return false;
	if (n1.m_dWidth != n2.m_dWidth)return false;
	if (n1.m_dHeight != n2.m_dHeight)return false;
	return false;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
