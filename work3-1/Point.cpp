/**
  ******************************************************************************
  * @file    Point.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Point class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Point.h"

/* Constructors & Deconstructor --------------------------------------------- */
Point::Point() :
	m_dCoordinateX(0),
	m_dCoordinateY(0)
{}

Point::Point(double t_dCoordinateX, double t_dCoordinateY) :
	m_dCoordinateX(t_dCoordinateX),
	m_dCoordinateY(t_dCoordinateY)
{}

Point::Point(const Point& source) :
	m_dCoordinateX(source.m_dCoordinateX),
	m_dCoordinateY(source.m_dCoordinateY)
{}

Point::~Point() {}

/* Getters & Setters -------------------------------------------------------- */
double Point::getX()const { return m_dCoordinateX; }
void Point::setX(double t_dCoordinateX) { m_dCoordinateX = t_dCoordinateX; }
double Point::getY()const { return m_dCoordinateY; }
void Point::setY(double t_dCoordinateY) { m_dCoordinateY = t_dCoordinateY; }
void Point::setXY(double t_dCoordinateX, double t_dCoordinateY) {
	m_dCoordinateX = t_dCoordinateX;
	m_dCoordinateY = t_dCoordinateY;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Point& source : ������ֵ
  * @retval ��
  */
void Point::operator=(const Point& source) {
	m_dCoordinateX = source.m_dCoordinateX;
	m_dCoordinateY = source.m_dCoordinateY;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Point& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Point& source) {
	//out << "(" << source.m_dCoordinateX << "," << source.m_dCoordinateY << ")";
	out << source.m_dCoordinateX << " " << source.m_dCoordinateY;
	return out;
}

/**
  * @brief ���ص��������
  * @param const Point& n1 : �������ߵ�ֵ
  * @param const Point& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Point& n1, const Point& n2) {
	if (n1.m_dCoordinateX != n2.m_dCoordinateX)return false;
	if (n1.m_dCoordinateY != n2.m_dCoordinateY)return false;
	return false;
}

/**
  * @brief ���ز����������
  * @param const Point& n1 : �������ߵ�ֵ
  * @param const Point& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 != n2
  */
bool operator!=(const Point& n1, const Point& n2) {
	return !(n1 == n2);
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
