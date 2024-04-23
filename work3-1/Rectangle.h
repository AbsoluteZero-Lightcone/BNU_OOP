/**
  ******************************************************************************
  * @file    Rectangle.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Rectangle class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __Rectangle_H
#define __Rectangle_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
using namespace std;
#include "Line.h"
/* Class ---------------------------------------------------------------------*/
class Rectangle {
private:
	Point m_pointCenter;
	double m_dWidth;
	double m_dHeight;

public:
	// Constructors & Deconstructor
	Rectangle();
	Rectangle(Point t_pointCenter, double t_dWidth, double m_dHeight);
	Rectangle(const Rectangle& source);
	~Rectangle();

	// Getter & Setter
	Point get_pointCenter()const;
	void set_pointCenter(Point t_pointCenter);
	double get_dWidth()const;
	void set_dWidth(double t_dWidth);
	double get_dHeight()const;
	void set_dHeight(double t_dHeight);
	Line getDiagonal()const;
	void setDiagonal(const Line& Diagonal);

	// Functions
	double area()const;
	double perimeter()const;
	bool isRectangle()const;

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Rectangle& source);

	friend ostream& operator<<(ostream& out, const Rectangle& source);
	friend bool operator==(const Rectangle& n1, const Rectangle& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Rectangle& source);
bool operator==(const Rectangle& n1, const Rectangle& n2);

#endif /* !__Rectangle_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
