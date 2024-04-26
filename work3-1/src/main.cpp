/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define DIRECTION_UR // ����ϵ����궨��
#include "demo.h"

#define LENGTH 10

int main() {
	/* �ļ��������� -------------------------------------- */
	ifstream infile(".\\res\\rect.txt", ios::in);
	Rectangle rectangles[LENGTH];
	double a, b, c, d;
	for (int i = 0; i < LENGTH; i++) {
		infile >> a >> b >> c >> d;
		rectangles[i].setDiagonal(Diagonal(Point(a, b), Point(c, d)));
	}
	/* չʾ���о��� -------------------------------------- */
	cout << "10 rectangles in arrRect��" << endl;
	for (int i = 0; i < LENGTH; i++) {
		try {
			rectangles[i].info();
		}
		catch (const char* err) {
			cerr << rectangles[i].getDiagonal() << " " << err << endl;
		}
	}
	/* ִ��Ҫ���� -------------------------------------- */
	cout << endl << "Move a rectangle :" << endl;
	Move_demo(rectangles, LENGTH);
	cout << endl << "Judge 2 rectangles intersect:" << endl;
	Intersect_demo(rectangles, LENGTH);
	/*--------------------------------------*/
	return 0;
}

/********* Zhang Yifa | fabsolute Zero Studio - Lightcone *******END OF FILE****/