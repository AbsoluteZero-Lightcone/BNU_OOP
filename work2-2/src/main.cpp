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
using namespace std;
#include "School.h"

int main() {
	char name[80],addr[80];
	cout << "Input school name: ";
	cin.getline(name, 80);
	cout << "Input school address: ";
	cin.getline(addr, 80);
	School myschool(name,addr);
	cout << "myschool:" << endl << myschool;
	School yourschool(myschool);
	cout << "yourschool:" << endl << yourschool;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
