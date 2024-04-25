/**
  ******************************************************************************
  * @file    Line.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.1
  * @date    2024-04-23
  * @brief   Line class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LINE_H
#define __LINE_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
using namespace std;
#include "Shape.h"
#include "Point.h"
#include "Rectangle.h"

/* Class ---------------------------------------------------------------------*/
class Line:public Shape {
private:
	Point m_pointP1;
	Point m_pointP2;
public:
	// Constructors & Deconstructor
	Line();
	Line(const Point& t_pointP1, const  Point& t_pointP2);
	Line(const Line& source);
	~Line();

	// Getter & Setter
	Point get_pointP1()const;
	void set_pointP1(Point t_pointP1);
	Point get_pointP2()const;
	void set_pointP2(Point t_pointP2);

	double length()const;

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Line& source);

	friend ostream& operator<<(ostream& out, const Line& source);
	friend bool operator==(const Line& n1, const Line& n2);

	friend class Point;
	friend class Rectangle;
	friend Shape& InterSectRect(const Rectangle& n1, const Rectangle& n2);

};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Line& source);
bool operator==(const Line& n1, const Line& n2);

#endif /* !__LINE_H */

/********* Zhang Yifa | fabsolute Zero Studio - Lightcone *******END OF FILE****/
