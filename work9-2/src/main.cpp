/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;
#include "MySet.h"

int main()
{
	MySet m1, m2, m3;
	cin >> m1 >> m2;
	m3 = m1 + m2;
	cout << m1 << '+' << m2 << '=' << m3 << endl;
	m3 = m1 - m2;
	cout << m1 << '-' << m2 << '=' << m3 << endl;
	cout << "m1=" << m1 << endl;
	m2 = ++m1;
	cout << "m2=++m1;  " << " m2=" << m2 << ",  m1=" << m1 << endl;
	m2 = m1++;
	cout << "m2=m1++;  " << " m2=" << m2 << ",  m1=" << m1 << endl;
	m2 = --m1;
	cout << "m2=--m1;  " << " m2=" << m2 << ",  m1=" << m1 << endl;
	m2 = m1--;
	cout << "m2=m1--;  " << " m2=" << m2 << ",  m1=" << m1 << endl;
	system("pause");
	return 0;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
