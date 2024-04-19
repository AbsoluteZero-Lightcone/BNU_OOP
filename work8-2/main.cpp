/**
  ******************************************************************************
  * @file    main.cpp
  * @author  张亦法
  * @date    2024-04-19
  * @brief   入口函数
  ******************************************************************************
  */
#include <fstream>
#include <string>
#include <iostream>
#include <cstdint>
using namespace std;
#include "Number.h"

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

int GCD(int a, int b) {
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	if (a == 0 || b == 0)
		throw "参与最大公因数计算的数值不能为0";
	if (a > b)swap(a, b);// 保证  n1 < n2
	int c = a % b;
	while (1) {
		if (b % c == 0)return c;
		// GCD 步骤数列： 
		// 变量	a   b    c
		//		a , b , a%b , a%(a%b) , ... , (n-2)%(n-1) , ... , GCD , 0
		// 数组向 <-- 方向移动
		a = b;
		b = c;
		c = a % b;
	}
}
class Fraction :public Sum {
private:
	int m_nNum;
	int m_nDen;
	// 正负号给分子
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


	// 规定动作
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
int main()
{
	Sum* ps1, * ps2;

	Number a(25.0), b(30.5);
	ps1 = &a; ps2 = &b;
	ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	Complex ca(1, 2), cb(3, 4);
	ps1 = &ca; ps2 = &cb;
	ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	Fraction fa(2, 3), fb(3, 4);
	ps1 = &fa; ps2 = &fb;
	ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	Huge_Int ha("+12345678901234567890"), hb("+99999999999999999999");
	ps1 = &ha; ps2 = &hb;
	ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	return 0;
}


/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
