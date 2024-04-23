/**
  ******************************************************************************
  * @file    Line.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Line class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Line.h"

/* Constructors & Deconstructor --------------------------------------------- */
Line::Line() :
	m_pointP1(0, 0),
	m_pointP2(1, 1)
{}

Line::Line(const Point& t_pointP1, const  Point& t_pointP2) :
	m_pointP1(t_pointP1),
	m_pointP2(t_pointP2)
{}

Line::Line(const Line& source) :
	m_pointP1(source.m_pointP1),
	m_pointP2(source.m_pointP2)
{}

Line::~Line() {}

/* Getters & Setters -------------------------------------------------------- */
Point Line::get_pointP1()const { return m_pointP1; }
void Line::set_pointP1(Point t_pointP1) { m_pointP1 = t_pointP1; }
Point Line::get_pointP2()const { return m_pointP2; }
void Line::set_pointP2(Point t_pointP2) { m_pointP2 = t_pointP2; }

/* Exported functions ------------------------------------------------------- */

double Line::length()const {
	return sqrt(
		(m_pointP1.m_dCoordinateX - m_pointP2.m_dCoordinateX) *
		(m_pointP1.m_dCoordinateX - m_pointP2.m_dCoordinateX) +
		(m_pointP1.m_dCoordinateY - m_pointP2.m_dCoordinateY) *
		(m_pointP1.m_dCoordinateY - m_pointP2.m_dCoordinateY)
	);
}

/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Line& source : ������ֵ
  * @retval ��
  */
void Line::operator=(const Line& source) {
	m_pointP1 = source.m_pointP1;
	m_pointP2 = source.m_pointP2;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Line& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Line& source) {
	// todo
	return out;
}

/**
  * @brief ���ص��������
  * @param const Line& n1 : �������ߵ�ֵ
  * @param const Line& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Line& n1, const Line& n2) {
	if (n1.m_pointP1 != n2.m_pointP1)return false;
	if (n1.m_pointP2 != n2.m_pointP2)return false;
	return false;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
