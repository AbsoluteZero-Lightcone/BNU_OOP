/**
  ******************************************************************************
  * @file    Rectangle.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.2.0
  * @date    2024-04-24
  * @brief   Rectangle class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Rectangle.h"

/* 坐标系方向定义 ------------------------------------------------------------- */
#if !defined(DIRECTION_UR) && !defined(DIRECTION_DR)
#define DIRECTION_UR // 坐标系方向默认值
#endif

#ifdef DIRECTION_UR // 平面直角坐标方向 向上为正
#define DIRECT_R(x,distance) ((x)+(distance))// 向右移动一段距离，可为负值
#define DIRECT_L(x,distance) ((x)-(distance))// 向左移动一段距离，可为负值
#define DIRECT_U(y,distance) ((y)+(distance))// 向上移动一段距离，可为负值
#define DIRECT_D(y,distance) ((y)-(distance))// 向下移动一段距离，可为负值
#define IS_INCREMENT_R(increment_x) ((increment_x)>=0)// x增量朝右
#define IS_INCREMENT_L(increment_x) ((increment_x)<=0)// x增量朝左
#define IS_INCREMENT_U(increment_y) ((increment_y)>=0)// y增量朝上
#define IS_INCREMENT_D(increment_y) ((increment_y)<=0)// y增量朝下
#define MORE_TO_THE_R(x1,x2) ((x1)>(x2)?(x1):(x2)) // 取更加靠右的一个
#define MORE_TO_THE_L(x1,x2) ((x1)<(x2)?(x1):(x2)) // 取更加靠左的一个
#define MORE_TO_THE_U(y1,y2) ((y1)>(y2)?(y1):(y2)) // 取更加靠上的一个
#define MORE_TO_THE_D(y1,y2) ((y1)<(y2)?(y1):(y2)) // 取更加靠下的一个
#define IS_MORE_TO_THE_R(x1,x2) ((x1)>(x2)) // 是否更加靠右
#define IS_MORE_TO_THE_L(x1,x2) ((x1)<(x2)) // 是否更加靠左
#define IS_MORE_TO_THE_U(y1,y2) ((y1)>(y2)) // 是否更加靠上
#define IS_MORE_TO_THE_D(y1,y2) ((y1)<(y2)) // 是否更加靠下
#endif	/* DIRECTION_UR */
#ifdef DIRECTION_DR // 左上角为原点，制图软件坐标方向 向下为正
#define DIRECT_R(x,distance) ((x)+(distance))// 向右移动一段距离，可为负值
#define DIRECT_L(x,distance) ((x)-(distance))// 向左移动一段距离，可为负值
#define DIRECT_U(y,distance) ((y)-(distance))// 向上移动一段距离，可为负值
#define DIRECT_D(y,distance) ((y)+(distance))// 向下移动一段距离，可为负值
#define IS_INCREMENT_R(increment_x) ((increment_x)>=0)// x增量朝右
#define IS_INCREMENT_L(increment_x) ((increment_x)<=0)// x增量朝左
#define IS_INCREMENT_U(increment_y) ((increment_y)<=0)// y增量朝上
#define IS_INCREMENT_D(increment_y) ((increment_y)>=0)// y增量朝下
#define MORE_TO_THE_R(x1,x2) ((x1)>(x2)?(x1):(x2)) // 取更加靠右的一个
#define MORE_TO_THE_L(x1,x2) ((x1)<(x2)?(x1):(x2)) // 取更加靠左的一个
#define MORE_TO_THE_U(y1,y2) ((y1)<(y2)?(y1):(y2)) // 取更加靠上的一个
#define MORE_TO_THE_D(y1,y2) ((y1)>(y2)?(y1):(y2)) // 取更加靠下的一个
#define IS_MORE_TO_THE_R(x1,x2) ((x1)>(x2)) // 是否更加靠右
#define IS_MORE_TO_THE_L(x1,x2) ((x1)<(x2)) // 是否更加靠左
#define IS_MORE_TO_THE_U(y1,y2) ((y1)<(y2)) // 是否更加靠上
#define IS_MORE_TO_THE_D(y1,y2) ((y1)>(y2)) // 是否更加靠下
#endif	/* DIRECTION_DR */
/* ------------------------------------------------------------- 坐标系方向定义 */

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

Rectangle::Rectangle(double x1, double y1, double x2, double y2):
	Rectangle(Diagonal(Point(x1, y1),Point(x2, y2)))
{}

Rectangle::Rectangle(const Rectangle& source) :
	m_pointCenter(source.m_pointCenter),
	m_dWidth(source.m_dWidth),
	m_dHeight(source.m_dHeight)
{}

Rectangle::Rectangle(const Diagonal& diagonal) {
	setDiagonal(diagonal);
}

Rectangle::~Rectangle() {}

/* Getters & Setters -------------------------------------------------------- */
Point  Rectangle::getCenter()const { return m_pointCenter; }
void   Rectangle::setCenter(Point t_pointCenter) { m_pointCenter = t_pointCenter; }
double Rectangle::getWidth()const { return m_dWidth; }
void   Rectangle::setWidth(double t_dWidth) { m_dWidth = t_dWidth; }
double Rectangle::getHeight()const { return m_dHeight; }
void   Rectangle::setHeight(double t_dHeight) { m_dHeight = t_dHeight; }

Point Rectangle::getLeftTop()const		{ return Point(DIRECT_L(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_U(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }
Point Rectangle::getLeftBottom()const	{ return Point(DIRECT_L(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_D(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }
Point Rectangle::getRightBottom()const	{ return Point(DIRECT_R(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_D(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }
Point Rectangle::getRightTop()const		{ return Point(DIRECT_R(m_pointCenter.m_dCoordinateX,m_dWidth / 2), DIRECT_U(m_pointCenter.m_dCoordinateY,m_dHeight / 2)); }

Line Rectangle::getLeftLine()const			{ return Line(getLeftTop(), getLeftBottom()); }
Line Rectangle::getRightLine()const			{ return Line(getRightTop(), getRightBottom()); }
Line Rectangle::getTopLine()const			{ return Line(getLeftTop(), getRightTop()); }
Line Rectangle::getBottomLine()const		{ return Line(getLeftBottom(), getRightBottom()); }

double Rectangle::getLeft()const   { return DIRECT_L(m_pointCenter.m_dCoordinateX,m_dWidth / 2);}
double Rectangle::getRight()const  { return DIRECT_R(m_pointCenter.m_dCoordinateX,m_dWidth / 2);}
double Rectangle::getTop()const    { return DIRECT_U(m_pointCenter.m_dCoordinateY,m_dHeight / 2);}
double Rectangle::getBottom()const { return DIRECT_D(m_pointCenter.m_dCoordinateY,m_dHeight / 2);}

/**
  * @brief 返回矩形的主对角线
  * @param 无
  * @retval 矩形的主对角线
  */
Diagonal Rectangle::getDiagonal()const {
	return Diagonal(getLeftTop(),getRightBottom());
}

/**
  * @brief 通过主/副对角线给矩形对象赋值
  * @param const Line& Diagonal : 矩形的主/副对角线
  * @retval 无
  */
void Rectangle::setDiagonal(const Diagonal& diagonal) {
	m_dWidth = fabs(diagonal.m_pointP1.m_dCoordinateX - diagonal.m_pointP2.m_dCoordinateX);
	m_dHeight = fabs(diagonal.m_pointP1.m_dCoordinateY - diagonal.m_pointP2.m_dCoordinateY);
	m_pointCenter.setXY(
		(diagonal.m_pointP1.m_dCoordinateX + diagonal.m_pointP2.m_dCoordinateX) / 2,
		(diagonal.m_pointP1.m_dCoordinateY + diagonal.m_pointP2.m_dCoordinateY) / 2
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

/* 两矩形相交 ---------------------------------------------------------------- */

#define INTERSECTRECT_METHOD 2  // 设置默认实现方法

#if INTERSECTRECT_METHOD == 1
/**
  * @brief 两矩形相交 方法1形心距方法
  * @param const Rectangle& n1, const Rectangle& n2 : 两个矩形
  * @retval 交集的图形，多态，返回基类引用
  */
Shape& InterSectRect(const Rectangle& n1, const Rectangle& n2) {
	// 所有情况：
	//       f1  f2   f3  f4  f5
	// 横向： 相离 外切 相交 内切 内含
	// 纵向： 相离 外切 相交 内切 内含
	// 共 25 种情况
	// 每种情况需要判断矩形的相对位置（4种情况）
	// 自由组合，合计 100 种情况
	#define f1(distance_center, sum, sub) (( distance_center > sum                          )?true:false)
	#define f2(distance_center, sum, sub) (( fabs(distance_center - sum) < DBL_EPSILON      )?true:false)
	#define f3(distance_center, sum, sub) (( distance_center < sum && distance_center > sub )?true:false)
	#define f4(distance_center, sum, sub) (( fabs(distance_center - sub) < DBL_EPSILON      )?true:false)
	#define f5(distance_center, sum, sub) (( distance_center < sub                          )?true:false)

	#define F1X f1(fabs(center_dx), sum_x, sub_x)
	#define F2X f2(fabs(center_dx), sum_x, sub_x)
	#define F3X f3(fabs(center_dx), sum_x, sub_x)
	#define F4X f4(fabs(center_dx), sum_x, sub_x)
	#define F5X f5(fabs(center_dx), sum_x, sub_x)

	#define F1Y f1(fabs(center_dy), sum_y, sub_y)
	#define F2Y f2(fabs(center_dy), sum_y, sub_y)
	#define F3Y f3(fabs(center_dy), sum_y, sub_y)
	#define F4Y f4(fabs(center_dy), sum_y, sub_y)
	#define F5Y f5(fabs(center_dy), sum_y, sub_y)

	double center_dx, center_dy; // 增量向量 n1->n2
	center_dx = n2.m_pointCenter.getX() - n1.m_pointCenter.getX();
	center_dy = n2.m_pointCenter.getY() - n1.m_pointCenter.getY();
	double sum_x, sum_y, sub_x, sub_y;
	sum_x = n1.m_dWidth / 2 + n2.m_dWidth / 2;
	sum_y = n1.m_dHeight / 2 + n2.m_dHeight / 2;
	sub_x = fabs(n1.m_dWidth / 2 - n2.m_dWidth / 2);
	sub_y = fabs(n1.m_dHeight / 2 - n2.m_dHeight / 2);

	if (center_dx == 0 && center_dy == 0){}
	if (center_dx == 0){}
	if (center_dy == 0){}
	if (F1X || F1Y) {
		static Empty intersectShape;
		return intersectShape; // 9种情况 空
	}
	else if (F2X && F2Y) { // 1种情况 点 
		static Point intersectShape;
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy)) { intersectShape = n1.getRightBottom(); return intersectShape; }// 矩形相对位置：n1左上->n2右下
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy)) { intersectShape = n1.getRightTop(); return intersectShape; }// 矩形相对位置：n1左下->n2右上
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy)) { intersectShape = n1.getLeftBottom(); return intersectShape; }// 矩形相对位置：n1右上->n2左下
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy)) { intersectShape = n1.getLeftTop(); return intersectShape; }// 矩形相对位置：n1右下->n2左上	
		throw "Error";
	}
	else if (F2X && !F5Y || F2Y && !F5X) {// 4种情况 线
		static Line intersectShape;
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy)){ intersectShape = Line(n2.getLeftTop(), n1.getRightBottom()); return intersectShape; } // 矩形相对位置：n1左上->n2右下
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy)){ intersectShape = Line(n2.getLeftBottom(), n1.getRightTop()); return intersectShape; }// 矩形相对位置：n1左下->n2右上
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy)){ intersectShape = Line(n2.getRightTop(), n1.getLeftBottom()); return intersectShape; }// 矩形相对位置：n1右上->n2左下
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy)){ intersectShape = Line(n2.getRightBottom(), n1.getLeftTop()); return intersectShape; }// 矩形相对位置：n1右下->n2左上
		throw "Error";
	}
	else if (F2X && F5Y) {// 1种情况 竖线
		static Line intersectShape;
		if (n1.m_dHeight < n2.m_dHeight) {
			if (IS_INCREMENT_R(center_dx)) {// 矩形相对位置：n1左->n2右
				if (n1.m_dHeight < n2.m_dHeight){ intersectShape = n1.getRightLine(); return intersectShape; }
				{ intersectShape = n2.getLeftLine(); return intersectShape; }
			}
			if (IS_INCREMENT_L(center_dx)) {// 矩形相对位置：n1右->n2左
				if (n1.m_dHeight < n2.m_dHeight){ intersectShape = n1.getLeftLine(); return intersectShape; }
				{ intersectShape = n2.getRightLine(); return intersectShape; }
			}
		}
		throw "Error";
	}
	else if (F2Y && F5X) {// 1种情况 横线
		static Line intersectShape;
		if (IS_INCREMENT_U(center_dy)) {// 矩形相对位置：n1下->n2上
			if (n1.m_dWidth < n2.m_dWidth){ intersectShape = n1.getTopLine(); return intersectShape; }
			{ intersectShape = n2.getBottomLine(); return intersectShape; }
		}
		if (IS_INCREMENT_D(center_dy)) {// 矩形相对位置：n1上->n2下
			if (n1.m_dWidth < n2.m_dWidth){ intersectShape = n1.getBottomLine(); return intersectShape; }
			{ intersectShape = n2.getTopLine(); return intersectShape; }
		}
		throw "Error";
	}
	else if ((F3X || F4X) && (F3Y || F4Y)) { // 4种情况 两角相交/取等时相切
		static Rectangle intersectShape;
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_D(center_dy)){ intersectShape = Rectangle(Diagonal(n2.getLeftTop(), n1.getRightBottom())); return intersectShape; }// 矩形相对位置：n1左上->n2右下
		if (IS_INCREMENT_R(center_dx) && IS_INCREMENT_U(center_dy)){ intersectShape = Rectangle(Diagonal(n2.getLeftBottom(), n1.getRightTop())); return intersectShape; }// 矩形相对位置：n1左下->n2右上
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_D(center_dy)){ intersectShape = Rectangle(Diagonal(n2.getRightTop(), n1.getLeftBottom())); return intersectShape; }// 矩形相对位置：n1右上->n2左下
		if (IS_INCREMENT_L(center_dx) && IS_INCREMENT_U(center_dy)){ intersectShape = Rectangle(Diagonal(n2.getRightBottom(), n1.getLeftTop())); return intersectShape; }// 矩形相对位置：n1右下->n2左上
		throw "Error";
	}
	else if ((F3X || F4X) && F5Y) { // 2种情况 一个竖边镶嵌在另一个上
		static Rectangle intersectShape;
		if (IS_INCREMENT_R(center_dx)) { // 矩形相对位置：n1左->n2右
			if (n1.m_dHeight < n2.m_dHeight) // n1小 n2大 
				// 小的一侧 在 另一个矩形 内部，成为交集的一个边
				// 交集的另一边由 小的侧边 和 大的靠近小的的一边 相交得到
				{ intersectShape = Rectangle(Diagonal(Point(n2.getLeft(), n1.getTop()), n1.getRightBottom())); return intersectShape; }
			else { intersectShape = Rectangle(Diagonal(n2.getLeftTop(), Point(n1.getRight(), n2.getBottom()))); return intersectShape; }
		}
		if (IS_INCREMENT_L(center_dx)) { // 矩形相对位置：n2左<-n1右
			if (n2.m_dHeight < n1.m_dHeight) // n2小 n1大
				{ intersectShape = Rectangle(Diagonal(Point(n1.getLeft(), n2.getTop()), n2.getRightBottom())); return intersectShape; }
			else { intersectShape = Rectangle(Diagonal(n1.getLeftTop(), Point(n2.getRight(), n1.getBottom()))); return intersectShape; }
		}
		throw "Error";
	}
	else if ((F3Y || F4Y) && F5X) { // 2种情况 一个横边镶嵌在另一个上
		static Rectangle intersectShape;
		if (IS_INCREMENT_U(center_dy)) {// 矩形相对位置：n2上<-n1下
			if (n1.m_dWidth > n2.m_dWidth) // n2小 n1大
				{ intersectShape = Rectangle(Diagonal(Point(n2.getLeft(), n1.getTop()), n2.getRightBottom())); return intersectShape; }
			else { intersectShape = Rectangle(Diagonal(n1.getLeftTop(), Point(n1.getRight(), n2.getBottom()))); return intersectShape; }
		}
		if (IS_INCREMENT_D(center_dy)) {// 矩形相对位置：n1上->n2下
			if (n2.m_dWidth > n1.m_dWidth) // n1小 n2大
				{ intersectShape = Rectangle(Diagonal(Point(n1.getLeft(), n2.getTop()), n1.getRightBottom())); return intersectShape; }
			else { intersectShape = Rectangle(Diagonal(n2.getLeftTop(), Point(n2.getRight(), n1.getBottom()))); return intersectShape; }
		}
		throw "Error";
	}
	else if (F5X && F5Y) {// 1种情况
		static Rectangle intersectShape;
		if (n1.m_dHeight <= n2.m_dHeight && n1.m_dWidth <= n2.m_dWidth) { // 包含
			intersectShape = n1;
			return intersectShape;
		}
		else if (n1.m_dHeight >= n2.m_dHeight && n1.m_dWidth >= n2.m_dWidth) { // 包含
			intersectShape = n2;
			return intersectShape;
		}
		else if (n1.m_dHeight > n2.m_dHeight && n1.m_dWidth < n2.m_dWidth) { // 穿插
			intersectShape = Rectangle(Point(n1.m_pointCenter.getX(), n2.m_pointCenter.getY()), n1.m_dWidth, n2.m_dHeight);
			return intersectShape;
		}
		else if (n1.m_dHeight < n2.m_dHeight && n1.m_dWidth > n2.m_dWidth) { // 穿插
			intersectShape = Rectangle(Point(n2.m_pointCenter.getX(), n1.m_pointCenter.getY()), n2.m_dWidth, n1.m_dHeight);
			return intersectShape;
		}
		throw "Error";
	}
	throw "Error";
}
#endif /* INTERSECTRECT_METHOD == 1 */
#if INTERSECTRECT_METHOD == 2
/**
  * @brief 两矩形相交 方法2 范围收缩方法
  * @param const Rectangle& n1, const Rectangle& n2 : 两个矩形
  * @retval 交集的图形，多态，返回基类引用
  */
Shape& InterSectRect(const Rectangle& n1, const Rectangle& n2) {
	double l = MORE_TO_THE_R(n1.getLeft(), n2.getLeft());
	double r = MORE_TO_THE_L(n1.getRight(), n2.getRight());
	double u = MORE_TO_THE_D(n1.getTop(), n2.getTop());
	double d = MORE_TO_THE_U(n1.getBottom(), n2.getBottom());
	if (IS_MORE_TO_THE_R(l, r) || IS_MORE_TO_THE_D(u, d)) {
		static Empty intersectShape;
		return intersectShape;
	}
	else if (l == r && u == d) {
		static Point intersectShape(l, u);
		return intersectShape;
	}
	else if (l == r) {
		static Line intersectShape(Point(l, u), Point(r, d));
		return intersectShape;
	}
	else if (u == d) {
		static Line intersectShape(Point(l,u), Point(r,d));
		return intersectShape;
	}
	else {
		static Rectangle intersectShape(l, u, r, d);
		return intersectShape;
	}
}
#endif /* INTERSECTRECT_METHOD == 2 */

/* ---------------------------------------------------------------- 两矩形相交 */

/********* Zhang Yifa | fabsolute Zero Studio - Lightcone *******END OF FILE****/
