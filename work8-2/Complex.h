/**
  ******************************************************************************
  * @file    Complex.h
  * @author  张亦法
  * @date    2024-04-20
  * @brief   复数类型
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
	Complex() :
		m_dReal(0.0), m_dImag(0.0)
	{}
	Complex(double t_dReal, double t_dImag) :
		m_dReal(t_dReal), m_dImag(t_dImag)
	{}
	Complex(const Complex& n) {
		m_dReal = n.m_dReal;
		m_dImag = n.m_dImag;
	}
	~Complex() {}
	// 规定动作
	void Show() {
		cout << m_dReal << "+" << m_dImag << "i";
	}
	void Add(Sum* num) {
		Complex* n = dynamic_cast<Complex*>(num);
		if (n != NULL) {
			Complex(*n + *this).Show();
		}
	}

	friend Complex operator+(const Complex& n1, const Complex& n2);
};
Complex operator+(const Complex& n1, const Complex& n2) {
	return Complex(n1.m_dReal + n2.m_dReal, n1.m_dImag + n2.m_dImag);
}



#endif // !__COMPLEX_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
