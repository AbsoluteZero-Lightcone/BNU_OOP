/**
  ******************************************************************************
  * @file    Complex.cpp
  * @author  张亦法 202311998186
  * @date    2024-04-20
  * @brief   复数类型
  ******************************************************************************
  */
#include "Complex.h"

Complex::Complex() :
	m_dReal(0.0), m_dImag(0.0)
{}
Complex::Complex(double t_dReal, double t_dImag) :
	m_dReal(t_dReal), m_dImag(t_dImag)
{}
Complex::Complex(const Complex& n) {
	m_dReal = n.m_dReal;
	m_dImag = n.m_dImag;
}
Complex::~Complex() {}
// 规定动作
void Complex::Show() {
	cout << m_dReal << "+" << m_dImag << "i";
}
void Complex::Add(Sum* num) {
	Complex* n = dynamic_cast<Complex*>(num);
	if (n != NULL) {
		Complex(*n + *this).Show();
	}
}

Complex operator+(const Complex& n1, const Complex& n2) {
	return Complex(n1.m_dReal + n2.m_dReal, n1.m_dImag + n2.m_dImag);
}



/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
