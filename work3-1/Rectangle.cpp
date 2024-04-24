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

Rectangle::Rectangle(const Line& Diagonal) {
	setDiagonal(Diagonal);
}

Rectangle::~Rectangle() {}

/* Getters & Setters -------------------------------------------------------- */
Point  Rectangle::getCenter()const { return m_pointCenter; }
void   Rectangle::setCenter(Point t_pointCenter) { m_pointCenter = t_pointCenter; }
double Rectangle::getWidth()const { return m_dWidth; }
void   Rectangle::setWidth(double t_dWidth) { m_dWidth = t_dWidth; }
double Rectangle::getHeight()const { return m_dHeight; }
void   Rectangle::setHeight(double t_dHeight) { m_dHeight = t_dHeight; }

// ����ϵ����궨��
#define __UR
#ifdef __UR // ƽ��ֱ�����귽�� ����Ϊ��
#define DIRECT_R(x,distance) (x+distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define DIRECT_L(x,distance) (x-distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define DIRECT_U(y,distance) (y+distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define DIRECT_D(y,distance) (y-distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define IS_INCREMENT_R(increment_x) ((increment_x>0)?true:false)// x��������
#define IS_INCREMENT_L(increment_x) ((increment_x<0)?true:false)// x��������
#define IS_INCREMENT_U(increment_y) ((increment_y>0)?true:false)// y��������
#define IS_INCREMENT_D(increment_y) ((increment_y<0)?true:false)// y��������
#endif	/* __UR */
#ifdef __DR // ���Ͻ�Ϊԭ�㣬��ͼ������귽�� ����Ϊ��
#define DIRECT_R(x,distance) (x+distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define DIRECT_L(x,distance) (x-distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define DIRECT_U(y,distance) (y-distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define DIRECT_D(y,distance) (y+distance)// �����ƶ�һ�ξ��룬��Ϊ��ֵ
#define IS_INCREMENT_R(increment_x) ((increment_x>0)?true:false)// x��������
#define IS_INCREMENT_L(increment_x) ((increment_x<0)?true:false)// x��������
#define IS_INCREMENT_U(increment_y) ((increment_y<0)?true:false)// y��������
#define IS_INCREMENT_D(increment_y) ((increment_y>0)?true:false)// y��������
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

void Rectangle::info() {
	if (isRectangle()) {
		cout << *this
			<< " area=" << area()
			<< " perimeter=" << perimeter()
			<< endl;
	}
	else {
		throw "Can��t construct rectangle.";
	}
}
Shape InterSectRect(const Rectangle& n1, const Rectangle& n2) {
	double center_dx, center_dy; // �������� n1->n2
	center_dx = n2.m_pointCenter.getX() - n1.m_pointCenter.getX();
	center_dy = n2.m_pointCenter.getY() - n1.m_pointCenter.getY();
	if (n1.m_dWidth / 2 + n2.m_dWidth / 2 > abs(center_dx) || n1.m_dHeight / 2 + n2.m_dHeight / 2 > abs(center_dy))return Empty();
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == abs(center_dx) && n1.m_dHeight / 2 + n2.m_dHeight / 2 == abs(center_dy)) { 
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy))return n1.getRightBottom();// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy))return n1.getRightTop();// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy))return n1.getLeftBottom();// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy))return n1.getLeftTop();// �������λ�ã�n1����->n2����	
	}
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == abs(center_dx) || n1.m_dHeight / 2 + n2.m_dHeight / 2 == abs(center_dy)){
		// ���ߺͺ��� �����ܽ᣺1.ָ��Է��Ķ�������µ�ͼ�� 2.��ҵ�������˳��û��Ҫ�󣬵���Line���캯�����Ѿ����߶α�׼��Ϊ�ɸ�����ָ��������
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy))return Line(n2.getLeftTop(),n1.getRightBottom()); // �������λ�ã�n1����->n2����
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy))return Line(n2.getLeftBottom(), n1.getRightTop());// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy))return Line(n2.getRightTop(), n1.getLeftBottom());// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy))return Line(n2.getRightBottom(), n1.getLeftTop());// �������λ�ã�n1����->n2����
		}
	else {
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy))return Rectangle(Line(n2.getLeftTop(),n1.getRightBottom()));// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy))return Rectangle(Line(n2.getLeftBottom(), n1.getRightTop()));// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy))return Rectangle(Line(n2.getRightTop(), n1.getLeftBottom()));// �������λ�ã�n1����->n2����
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy))return Rectangle(Line(n2.getRightBottom(), n1.getLeftTop()));// �������λ�ã�n1����->n2����
		}
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
