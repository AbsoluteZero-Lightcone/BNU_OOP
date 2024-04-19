/**
  ******************************************************************************
  * @file    main.cpp
  * @author  ���෨
  * @date    2024-04-19
  * @brief   ��ں���
  ******************************************************************************
  */
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
class Number {
private:

};
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
	ps1 = hfa; ps2 = &hb;
	ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	return 0;
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
