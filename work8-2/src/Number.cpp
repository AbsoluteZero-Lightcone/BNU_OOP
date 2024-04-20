/**
  ******************************************************************************
  * @file    Number.cpp
  * @author  张亦法 202311998186
  * @date    2024-04-20
  * @brief   浮点数类型
  ******************************************************************************
  */
#include "Number.h"

Number::Number() :m_dData(0.0) {}
Number::Number(double t_dData) :m_dData(t_dData) {}
Number::Number(const Number& n) {
	m_dData = n.m_dData;
}
Number::~Number() {}
// 规定动作
void Number::Show() {
	cout << m_dData;
}
void Number::Add(Sum* num) {
	Number* n = dynamic_cast<Number*>(num);
	if (n != NULL) {
		Number(*n + *this).Show();
	}
}
Number operator+(const Number& n1, const Number& n2) {
	return Number(n1.m_dData + n2.m_dData);
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
