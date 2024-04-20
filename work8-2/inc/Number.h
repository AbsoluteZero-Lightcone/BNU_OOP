/**
  ******************************************************************************
  * @file    Number.h
  * @author  ���෨ 202311998186
  * @date    2024-04-20
  * @brief   ����������
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
	Number();
	Number(double t_dData);
	Number(const Number& n);
	~Number();
	// �涨����
	void Show();
	void Add(Sum* num);
	friend Number operator+(const Number& n1, const Number& n2);
};
Number operator+(const Number& n1, const Number& n2);

#endif // !__NUMBER_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
