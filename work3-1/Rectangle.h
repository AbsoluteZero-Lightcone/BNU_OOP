/**
  ******************************************************************************
  * @file    Rectangle.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
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
#include "Point.h"
#include "Line.h"
#include "Shape.h"

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

	Line getLeft()const;
	Line getRight()const;
	Line getTop()const;
	Line getBottom()const;

	// Functions
	double area()const;
	double perimeter()const;
	bool isRectangle()const;
	void offset(double x, double y);
	void info();

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Rectangle& source);

	friend ostream& operator<<(ostream& out, const Rectangle& source);
	friend bool operator==(const Rectangle& n1, const Rectangle& n2);

	friend Shape InterSectRect(const Rectangle& n1, const Rectangle& n2);

};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Rectangle& source);
bool operator==(const Rectangle& n1, const Rectangle& n2);

Shape InterSectRect(const Rectangle& n1, const Rectangle& n2);

#endif /* !__RECTANGLE_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
