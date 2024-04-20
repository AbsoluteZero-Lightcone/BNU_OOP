/**
  ******************************************************************************
  * @file    Fraction.h
  * @author  张亦法 202311998186
  * @date    2024-04-20
  * @brief   分数类型
  ******************************************************************************
  */
#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>
using namespace std;
#include "Sum.h"

int GCD(int a, int b);
class Fraction :public Sum {
private:
	int m_nNum;
	int m_nDen;
	// 正负号给分子
	void Format();
public:
	Fraction(const Fraction& n);
	Fraction(int n = 0, int d = 1);
	~Fraction();


	// 规定动作
	void Show();
	void Add(Sum* num);

	friend Fraction operator+(const Fraction& n1, const Fraction& n2);
};
Fraction operator+(const Fraction& n1, const Fraction& n2);

#endif // !__FRACTION_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
