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
#include "Sum.h"

class Number :public Sum {
private:
	double m_dData;
public:
};
class Complex :public Sum {
private:
	double m_dReal;
	double m_dImag;
public:
};
class Fraction :public Sum {
private:
	int m_nNum;
	int m_nDen;
public:
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
