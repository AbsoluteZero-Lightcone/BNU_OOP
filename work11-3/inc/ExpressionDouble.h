/**
  ******************************************************************************
  * @file    ExpressionDouble.h
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
  * @date    2024-05-20
  * @brief   ExpressionDouble
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXPRESSIONDOUBLE_H
#define __EXPRESSIONDOUBLE_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "ExpressionElement_Base.h"

/* Class ---------------------------------------------------------------------*/
class ExpressionDouble :public ExpressionElement_Base {
	double m_dData;
public:
	ExpressionDouble(double d = 0);
	ExpressionDouble(string s);
	ExpressionDouble(const ExpressionDouble& e);
	ExpressionDouble& operator=(const ExpressionDouble& e);
	operator double()const;
	void fetch(string& s);
	friend ostream& operator<<(ostream& out, const ExpressionDouble& e);
	friend ExpressionDouble operator+(const ExpressionDouble& a, const ExpressionDouble& b);
	friend ExpressionDouble operator-(const ExpressionDouble& a, const ExpressionDouble& b);
	friend ExpressionDouble operator*(const ExpressionDouble& a, const ExpressionDouble& b);
	friend ExpressionDouble operator/(const ExpressionDouble& a, const ExpressionDouble& b);
};
/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const ExpressionDouble& e);
ExpressionDouble operator+(const ExpressionDouble& a, const ExpressionDouble& b);
ExpressionDouble operator-(const ExpressionDouble& a, const ExpressionDouble& b);
ExpressionDouble operator*(const ExpressionDouble& a, const ExpressionDouble& b);
ExpressionDouble operator/(const ExpressionDouble& a, const ExpressionDouble& b);
#endif /* !__ExpressionDouble_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
