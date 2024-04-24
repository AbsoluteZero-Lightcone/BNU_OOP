/**
  ******************************************************************************
  * @file    Rectangle.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Rectangle class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Rectangle.h"

/* Constructors & Deconstructor --------------------------------------------- */
Rectangle::Rectangle() :
	m_pointCenter(0, 0),
	m_dWidth(1),
	m_dHeight(1)
{}

Rectangle::Rectangle(Point t_pointCenter, double t_dWidth, double t_dHeight) :
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
Point  Rectangle::getCenter()const { return m_pointCenter; }
void   Rectangle::setCenter(Point t_pointCenter) { m_pointCenter = t_pointCenter; }
double Rectangle::getWidth()const { return m_dWidth; }
void   Rectangle::setWidth(double t_dWidth) { m_dWidth = t_dWidth; }
double Rectangle::getHeight()const { return m_dHeight; }
void   Rectangle::setHeight(double t_dHeight) { m_dHeight = t_dHeight; }

// ����ϵ����궨��
#define __DR
#ifdef __UR // ƽ��ֱ�����귽�� ����Ϊ��
#define DIRECT_R(x,increment) (x+increment)// ����
#define DIRECT_L(x,increment) (x-increment)// ����
#define DIRECT_U(y,increment) (y+increment)// ����
#define DIRECT_D(y,increment) (y-increment)// ����
#endif	/* __UR */
#ifdef __DR // ���Ͻ�Ϊԭ�㣬��ͼ������귽�� ����Ϊ��
#define DIRECT_R(x,increment) (x+increment)// ����
#define DIRECT_L(x,increment) (x-increment)// ����
#define DIRECT_U(y,increment) (y-increment)// ����
#define DIRECT_D(y,increment) (y+increment)// ����
#endif	/* __DR */
Point Rectangle::getLeftTop()const		{ return Point(DIRECT_L(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_U(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }
Point Rectangle::getLeftBottom()const	{ return Point(DIRECT_L(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_D(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }
Point Rectangle::getRightBottom()const	{ return Point(DIRECT_R(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_D(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }
Point Rectangle::getRightTop()const		{ return Point(DIRECT_R(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_U(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }

Line Rectangle::getLeft()const			{ return Line(getLeftTop(), getLeftBottom()); }
Line Rectangle::getRight()const			{ return Line(getRightTop(), getRightBottom()); }
Line Rectangle::getTop()const			{ return Line(getLeftTop(), getRightTop()); }
Line Rectangle::getBottom()const		{ return Line(getLeftBottom(), getRightBottom()); }

/**
  * @brief ���ؾ��ε����Խ���
  * @param ��
  * @retval ���ε����Խ���
  */
Line Rectangle::getDiagonal()const {
	return Line(getLeftTop(),getRightBottom());
}

/**
  * @brief ͨ�����Խ��߸����ζ���ֵ
  * @param const Line& Diagonal : ���ε����Խ���
  * @retval ��
  */
void Rectangle::setDiagonal(const Line& Diagonal) {
	m_dWidth = abs(Diagonal.m_pointP1.m_dCoordinateX - Diagonal.m_pointP2.m_dCoordinateX);
	m_dHeight = abs(Diagonal.m_pointP1.m_dCoordinateY - Diagonal.m_pointP2.m_dCoordinateY);
	m_pointCenter.setXY(
		(Diagonal.m_pointP1.m_dCoordinateX + Diagonal.m_pointP2.m_dCoordinateX) / 2,
		(Diagonal.m_pointP1.m_dCoordinateY + Diagonal.m_pointP2.m_dCoordinateY) / 2
	);
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief �����
  * @param ��
  * @retval ���
  */
double Rectangle::area()const {
	return m_dWidth * m_dHeight;
}

/**
  * @brief ���ܳ�
  * @param ��
  * @retval �ܳ�
  */
double Rectangle::perimeter()const {
	return (m_dWidth + m_dHeight) * 2;
}

/**
  * @brief �������Ϊ0����Ϊ��ʱ�����ɾ��Σ��ô˺����ж��Ƿ��ܹ��ɾ���
  * @param ��
  * @retval bool, 1 for �ܹ��ɾ���
  */
bool Rectangle::isRectangle()const {
	if (m_dWidth == 0 || m_dHeight == 0)return false;
	return true;
}

/**
  * @brief �ƶ�����
  * @param double dx, double dy : ƫ����
  * @retval ��
  */
void Rectangle::offset(double dx, double dy) {
	m_pointCenter.m_dCoordinateX += dx;
	m_pointCenter.m_dCoordinateY += dy;
}

Shape InterSectRect(const Rectangle& n1, const Rectangle& n2) {
	double center_dx, center_dy;
	center_dx = n1.m_pointCenter.m_dCoordinateX - n2.m_pointCenter.m_dCoordinateX;
	center_dy = n1.m_pointCenter.m_dCoordinateY - n2.m_pointCenter.m_dCoordinateY;
	if (n1.m_dWidth / 2 + n2.m_dWidth / 2 > abs(center_dx) || n1.m_dHeight / 2 + n2.m_dHeight / 2 > abs(center_dy))return Empty();
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == abs(center_dx) && n1.m_dHeight / 2 + n2.m_dHeight / 2 == abs(center_dy))return Point();
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == abs(center_dx))return Line();
	else if (n1.m_dHeight / 2 + n2.m_dHeight / 2 == abs(center_dy))return Line();
	else return Rectangle();
}

/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Rectangle& source : ������ֵ
  * @retval ��
  */
void Rectangle::operator=(const Rectangle& source) {
	m_pointCenter = source.m_pointCenter;
	m_dWidth = source.m_dWidth;
	m_dHeight = source.m_dHeight;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Rectangle& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Rectangle& source) {
	out << "Rect(" << source.getDiagonal() << ")";
	return out;
}

/**
  * @brief ���ص��������
  * @param const Rectangle& n1 : �������ߵ�ֵ
  * @param const Rectangle& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Rectangle& n1, const Rectangle& n2) {
	if (n1.m_pointCenter != n2.m_pointCenter)return false;
	if (n1.m_dWidth != n2.m_dWidth)return false;
	if (n1.m_dHeight != n2.m_dHeight)return false;
	return false;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
