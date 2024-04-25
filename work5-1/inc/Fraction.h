/**
  ******************************************************************************
  * @file    Fraction.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Fraction class
  * @encode  GB2312
  ******************************************************************************
  */
#ifndef __FRACTION_H
#define __FRACTION_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Fraction {
private:
	int m_nNum;
	int m_nDen;
	// 正负号给分子
	void Standardize();
public:
	Fraction(const Fraction& n);
	Fraction(int n = 0, int d = 1);
	~Fraction();

	// 规定动作
	void Show()const;
	void Set(int, int);

	// 运算符重载
	void operator=(const Fraction& source);

	friend ostream& operator<<(ostream& out, const Fraction& source);
	friend bool operator==(const Fraction& n1, const Fraction& n2);

	friend Fraction operator-(Fraction n);
	friend Fraction operator+(const Fraction& n1, const Fraction& n2);
	friend Fraction operator-(const Fraction& n1, const Fraction& n2);
	friend Fraction operator*(const Fraction& n1, const Fraction& n2);
	friend Fraction operator/(const Fraction& n1, const Fraction& n2);
};

ostream& operator<<(ostream& out, const Fraction& source);
bool operator==(const Fraction& n1, const Fraction& n2);
Fraction operator-(Fraction n);
Fraction operator+(const Fraction& n1, const Fraction& n2);
Fraction operator-(const Fraction& n1, const Fraction& n2);
Fraction operator*(const Fraction& n1, const Fraction& n2);
Fraction operator/(const Fraction& n1, const Fraction& n2);

/* Exported functions ------------------------------------------------------- */
int GCD(int, int);

#endif // !__FRACTION_H

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
