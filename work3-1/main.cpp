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
#include "Rectangle.h"

int main() {
	ifstream infile("rect.txt", ios::in);
	Rectangle rectangles[10];
	double a, b, c, d;
	for (int i = 0; i < 10; i++) {
		infile >> a >> b >> c >> d;
		rectangles[i].setDiagonal(Line(Point(a, b), Point(c, d)));
	}
	for (int i = 0; i < 10; i++) {
		if (rectangles[i].isRectangle()) {
			cout << rectangles[i]
				<< " area=" << rectangles[i].area()
				<< " perimeter=" << rectangles[i].perimeter()
				<< endl;
		}
		else {
			cerr << rectangles[i].getDiagonal() << " Can¡®t construct rectangle." << endl;
		}
	}
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
