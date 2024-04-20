/**
  ******************************************************************************
  * @file    Fraction.h
  * @author  ���෨ 202311998186
  * @date    2024-04-20
  * @brief   ��������
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
	// �����Ÿ�����
	void Format();
public:
	Fraction(const Fraction& n);
	Fraction(int n = 0, int d = 1);
	~Fraction();


	// �涨����
	void Show();
	void Add(Sum* num);

	friend Fraction operator+(const Fraction& n1, const Fraction& n2);
};
Fraction operator+(const Fraction& n1, const Fraction& n2);

#endif // !__FRACTION_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
