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
	// Constructors & Deconstructor
	Triangle();
	Triangle(
		double t_dSide1,
		double t_dSide2,
		double t_dSide3
	);
	~Triangle();

	// Getter & Setter
	double get_dSide1()const;
	double get_dSide2()const;
	double get_dSide3()const;
	void set_dSide1(double t_dSide1);
	void set_dSide2(double t_dSide2);
	void set_dSide3(double t_dSide3);

	void SetLen(double t_dSide1, double t_dSide2, double t_dSide3);

	bool IsTriangle();
	bool Equilateral();
	bool Isosceles();
	bool RightTriangle();
	double Area();
	double Perimeter();

};

#endif /* !__Triangle_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
