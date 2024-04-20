/**
  ******************************************************************************
  * @file    Complex.h
  * @author  ���෨ 202311998186
  * @date    2024-04-20
  * @brief   ��������
  ******************************************************************************
  */
#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>
using namespace std;
#include "Sum.h"

class Complex :public Sum {
private:
	double m_dReal;
	double m_dImag;
public:
	Complex();
	Complex(double t_dReal, double t_dImag);
	Complex(const Complex& n);
	~Complex();
	// �涨����
	void Show();
	void Add(Sum* num);

	friend Complex operator+(const Complex& n1, const Complex& n2);
};
Complex operator+(const Complex& n1, const Complex& n2);

#endif // !__COMPLEX_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
