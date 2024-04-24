/**
  ******************************************************************************
  * @file    Triangle.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Triangle class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __Triangle_H
#define __Triangle_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Triangle {
private:
	double m_dSide1;
	double m_dSide2;
	double m_dSide3;
public:

	Triangle();

	// Getter & Setter
	double get_dSide1()const;
	double get_dSide2()const;
	double get_dSide3()const;
	void set_dSide1(double t_dSide1);
	void set_dSide2(double t_dSide2);
	void set_dSide3(double t_dSide3);

	void SetLen(double t_dSide1, double t_dSide2, double t_dSide3);

	bool IsTriangle()const;
	bool Equilateral()const;
	bool Isosceles()const;
	bool RightTriangle()const;
	double Area()const;
	double Perimeter()const;

	friend ostream& operator<<(ostream& out, const Triangle& source);
};

ostream& operator<<(ostream& out, const Triangle& source);

#endif /* !__Triangle_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
