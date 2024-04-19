/**
  ******************************************************************************
  * @file    Fraction.h
  * @author  ���෨
  * @date    2024-04-20
  * @brief   ��������
  ******************************************************************************
  */
#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>
using namespace std;
#include "Sum.h"

int GCD(int a, int b) {
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	if (a == 0 || b == 0)
		throw "������������������ֵ����Ϊ0";
	if (a > b)swap(a, b);// ��֤  n1 < n2
	int c = a % b;
	while (1) {
		if (b % c == 0)return c;
		// GCD �������У� 
		// ����	a   b    c
		//		a , b , a%b , a%(a%b) , ... , (n-2)%(n-1) , ... , GCD , 0
		// ������ <-- �����ƶ�
		a = b;
		b = c;
		c = a % b;
	}
}
class Fraction :public Sum {
private:
	int m_nNum;
	int m_nDen;
	// �����Ÿ�����
	void Format() {
		if (m_nNum == 0)m_nDen = 1;
		else {
			int gcd = GCD(m_nNum, m_nDen);
			m_nNum /= gcd;
			m_nDen /= gcd;
		}
	}
public:
	Fraction(const Fraction& n) {
		m_nNum = n.m_nNum;
		m_nDen = n.m_nDen;
	}
	Fraction(int n = 0, int d = 1) {
		m_nNum = n;
		m_nDen = d;
		Format();
	}
	~Fraction() {}


	// �涨����
	void Show() {
		cout << m_nNum << "/" << m_nDen;
	}
	void Add(Sum* num) {
		Fraction* n = dynamic_cast<Fraction*>(num);
		if (n != NULL) {
			Fraction(*n + *this).Show();
		}
	}

	friend Fraction operator+(const Fraction& n1, const Fraction& n2);
};
Fraction operator+(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen + n1.m_nDen * n2.m_nNum;
	f.Format();
	return f;
}


#endif // !__FRACTION_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
