/**
  ******************************************************************************
  * @file    Number.h
  * @author  张亦法
  * @date    2024-04-20
  * @brief   浮点数类型
  ******************************************************************************
  */
#ifndef __NUMBER_H
#define __NUMBER_H

#include <iostream>
using namespace std;
#include "Sum.h"

class Number :public Sum {
private:
	double m_dData;
public:
	Number() :m_dData(0.0) {}
	Number(double t_dData) :m_dData(t_dData) {}
	Number(const Number& n) {
		m_dData = n.m_dData;
	}
	~Number() {}
	// 规定动作
	void Show() {
		cout << m_dData;
	}
	void Add(Sum* num) {
		Number* n = dynamic_cast<Number*>(num);
		if (n != NULL) {
			Number(*n + *this).Show();
		}
	}
	friend Number operator+(const Number& n1, const Number& n2);
};
Number operator+(const Number& n1, const Number& n2) {
	return Number(n1.m_dData + n2.m_dData);
}

#endif // !__NUMBER_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
