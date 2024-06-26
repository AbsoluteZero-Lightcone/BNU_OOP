/**
  ******************************************************************************
  * @file    Rectangle.h
  * @author  Zhang Yifa 202311998186
  * @version V1.2.0
  * @date    2024-04-24
  * @brief   Rectangle class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RECTANGLE_H
#define __RECTANGLE_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
using namespace std;
#include "Shape.h"
#include "Empty.h"
#include "Line.h"

/* Typedefs ------------------------------------------------------------------*/
typedef Line Diagonal;

/* Class ---------------------------------------------------------------------*/
class Rectangle:public Shape {
private:
	Point m_pointCenter;
	double m_dWidth;
	double m_dHeight;

public:
	// Constructors & Deconstructor
	Rectangle();
	Rectangle(Point t_pointCenter, double t_dWidth, double m_dHeight);
	Rectangle(double x1,double y1,double x2,double y2);
	Rectangle(const Rectangle& source);
	Rectangle(const Diagonal& diagonal);
	~Rectangle();

	// Getter & Setter
	double getWidth()const;
	void setWidth(double t_dWidth);
	double getHeight()const;
	void setHeight(double t_dHeight);

	Diagonal getDiagonal()const;
	void setDiagonal(const Diagonal& diagonal);

	void setCenter(Point t_pointCenter);

	Point getCenter()const;

	Point getLeftTop()const;
	Point getLeftBottom()const;
	Point getRightBottom()const;
	Point getRightTop()const;

	Line getLeftLine()const;
	Line getRightLine()const;
	Line getTopLine()const;
	Line getBottomLine()const;

	double getLeft()const;
	double getRight()const;
	double getTop()const;
	double getBottom()const;

	// Functions
	double area()const;
	double perimeter()const;
	bool isRectangle()const;
	void offset(double x, double y);
	void info();

	// ���������
	void operator=(const Rectangle& source);

	friend ostream& operator<<(ostream& out, const Rectangle& source);
	friend bool operator==(const Rectangle& n1, const Rectangle& n2);

	friend Shape& InterSectRect(const Rectangle& n1, const Rectangle& n2);

};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Rectangle& source);
bool operator==(const Rectangle& n1, const Rectangle& n2);

Shape& InterSectRect(const Rectangle& n1, const Rectangle& n2);

#endif /* !__RECTANGLE_H */

/********* Zhang Yifa | fabsolute Zero Studio - Lightcone *******END OF FILE****/
