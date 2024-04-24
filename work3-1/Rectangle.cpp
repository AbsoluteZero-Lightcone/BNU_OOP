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

// 坐标系方向宏定义
#define __UR
#ifdef __UR // 平面直角坐标方向 向上为正
#define DIRECT_R(x,distance) (x+distance)// 向右移动一段距离，可为负值
#define DIRECT_L(x,distance) (x-distance)// 向左移动一段距离，可为负值
#define DIRECT_U(y,distance) (y+distance)// 向上移动一段距离，可为负值
#define DIRECT_D(y,distance) (y-distance)// 向下移动一段距离，可为负值
#define IS_INCREMENT_R(increment_x) ((increment_x>0)?true:false)// x增量朝右
#define IS_INCREMENT_L(increment_x) ((increment_x<0)?true:false)// x增量朝左
#define IS_INCREMENT_U(increment_y) ((increment_y>0)?true:false)// y增量朝上
#define IS_INCREMENT_D(increment_y) ((increment_y<0)?true:false)// y增量朝下
#endif	/* __UR */
#ifdef __DR // 左上角为原点，制图软件坐标方向 向下为正
#define DIRECT_R(x,distance) (x+distance)// 向右移动一段距离，可为负值
#define DIRECT_L(x,distance) (x-distance)// 向左移动一段距离，可为负值
#define DIRECT_U(y,distance) (y-distance)// 向上移动一段距离，可为负值
#define DIRECT_D(y,distance) (y+distance)// 向下移动一段距离，可为负值
#define IS_INCREMENT_R(increment_x) ((increment_x>0)?true:false)// x增量朝右
#define IS_INCREMENT_L(increment_x) ((increment_x<0)?true:false)// x增量朝左
#define IS_INCREMENT_U(increment_y) ((increment_y<0)?true:false)// y增量朝上
#define IS_INCREMENT_D(increment_y) ((increment_y>0)?true:false)// y增量朝下
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
  * @brief 返回矩形的主对角线
  * @param 无
  * @retval 矩形的主对角线
  */
Line Rectangle::getDiagonal()const {
	return Line(getLeftTop(),getRightBottom());
}

/**
  * @brief 通过主对角线给矩形对象赋值
  * @param const Line& Diagonal : 矩形的主对角线
  * @retval 无
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
  * @brief 求面积
  * @param 无
  * @retval 面积
  */
double Rectangle::area()const {
	return m_dWidth * m_dHeight;
}

/**
  * @brief 求周长
  * @param 无
  * @retval 周长
  */
double Rectangle::perimeter()const {
	return (m_dWidth + m_dHeight) * 2;
}

/**
  * @brief 长宽可以为0，但为零时不构成矩形，用此函数判断是否能构成矩形
  * @param 无
  * @retval bool, 1 for 能构成矩形
  */
bool Rectangle::isRectangle()const {
	if (m_dWidth == 0 || m_dHeight == 0)return false;
	return true;
}

/**
  * @brief 移动矩形
  * @param double dx, double dy : 偏移量
  * @retval 无
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
		throw "Can’t construct rectangle.";
	}
}
Shape InterSectRect(const Rectangle& n1, const Rectangle& n2) {
	double center_dx, center_dy; // 增量向量 n1->n2
	center_dx = n2.m_pointCenter.getX() - n1.m_pointCenter.getX();
	center_dy = n2.m_pointCenter.getY() - n1.m_pointCenter.getY();
	if (n1.m_dWidth / 2 + n2.m_dWidth / 2 > abs(center_dx) || n1.m_dHeight / 2 + n2.m_dHeight / 2 > abs(center_dy))return Empty();
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == abs(center_dx) && n1.m_dHeight / 2 + n2.m_dHeight / 2 == abs(center_dy)) { 
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy))return n1.getRightBottom();// 矩形相对位置：n1左上->n2右下
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy))return n1.getRightTop();// 矩形相对位置：n1左下->n2右上
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy))return n1.getLeftBottom();// 矩形相对位置：n1右上->n2左下
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy))return n1.getLeftTop();// 矩形相对位置：n1右下->n2左上	
	}
	else if (n1.m_dWidth / 2 + n2.m_dWidth / 2 == abs(center_dx) || n1.m_dHeight / 2 + n2.m_dHeight / 2 == abs(center_dy)){
		// 竖线和横线 规律总结：1.指向对方的顶点组成新的图形 2.作业中两点的顺序没有要求，但在Line构造函数中已经把线段标准化为由负方向指向正方向
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy))return Line(n2.getLeftTop(),n1.getRightBottom()); // 矩形相对位置：n1左上->n2右下
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy))return Line(n2.getLeftBottom(), n1.getRightTop());// 矩形相对位置：n1左下->n2右上
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy))return Line(n2.getRightTop(), n1.getLeftBottom());// 矩形相对位置：n1右上->n2左下
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy))return Line(n2.getRightBottom(), n1.getLeftTop());// 矩形相对位置：n1右下->n2左上
		}
	else {
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy))return Rectangle(Line(n2.getLeftTop(),n1.getRightBottom()));// 矩形相对位置：n1左上->n2右下
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy))return Rectangle(Line(n2.getLeftBottom(), n1.getRightTop()));// 矩形相对位置：n1左下->n2右上
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy))return Rectangle(Line(n2.getRightTop(), n1.getLeftBottom()));// 矩形相对位置：n1右上->n2左下
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy))return Rectangle(Line(n2.getRightBottom(), n1.getLeftTop()));// 矩形相对位置：n1右下->n2左上
		}
}

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
	out << "Rect(" << source.getDiagonal() << ")";
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
