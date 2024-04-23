/**
  ******************************************************************************
  * @file    Point.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Point class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __POINT_H
#define __POINT_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Point {
private:
	double m_dCoordinateX;
	double m_dCoordinateY;
public:
	// Constructors & Deconstructor
	Point();
	Point(double t_dCoordinateX, double t_dCoordinateY);
	Point(const Point& source);
	~Point();

	// Getter & Setter
	double getX()const;
	void setX(double t_dCoordinateX);
	double getY()const;
	void setY(double t_dCoordinateY);
	void setXY(double t_dCoordinateX, double t_dCoordinateY);

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Point& source);

	friend ostream& operator<<(ostream& out, const Point& source);
	friend bool operator==(const Point& n1, const Point& n2);

	friend class Line;
	friend class Rectangle;
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Point& source);
bool operator==(const Point& n1, const Point& n2);
bool operator!=(const Point& n1, const Point& n2);

#endif /* !__POINT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
