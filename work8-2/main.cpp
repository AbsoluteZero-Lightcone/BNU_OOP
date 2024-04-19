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
	~Number() {}
	// 规定动作
	void Show();
	void Add(Sum* num);
};
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
		~Complex() {}
	// 规定动作
	void Show();
	void Add(Sum* num);
};
int GCD(int a, int b) {
	if (a == b)return a;// 剪枝
	if (a > b)swap(a, b);// 保证  n1 < n2
	int c = a % b;
	while (1) {
		// GCD 步骤数列： 
		// a   b    c
		//     a    b      c
		// a , b , a%b , a%(a%b) , ... , (n-2)%(n-1) , ... , GCD , 0
		// 数组向cba方向移动
		a = b;
		b = c;
		c = a % b;
		if (b % c == 0)return c;
	}
}
class Fraction :public Sum {
private:
	int m_nNum;
	int m_nDen;

	void Format();
public:
	Fraction(int n = 0, int d = 1);
	~Fraction() {}


	// 规定动作
	void Show();
	void Add(Sum* num);


};

int main()
{
	Sum* ps1, * ps2;
	//cout << typeid(class Huge_Int).name() << endl;
	// 
	//Number a(25.0), b(30.5);
	//ps1 = &a; ps2 = &b;
	//ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	//Complex ca(1, 2), cb(3, 4);
	//ps1 = &ca; ps2 = &cb;
	//ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	//Fraction fa(2, 3), fb(3, 4);
	//ps1 = &fa; ps2 = &fb;
	//ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	Huge_Int ha("123"), hb("-999");
	ps1 = &ha; ps2 = &hb;
	ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;
	cout << ha + hb << endl;
	cout << ha - hb << endl;
	return 0;
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
