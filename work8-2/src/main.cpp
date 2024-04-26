/**
  ******************************************************************************
  * @file    main.cpp
  * @author  张亦法 202311998186
  * @date    2024-04-20
  * @brief   入口函数
  ******************************************************************************
  */
#include <iostream>
using namespace std;
#include "Numbers.h"

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
	system("pause");
	return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
