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

int input_index(int length, int n) {
	int i;
	cout << "Input no. of rectangle" << n << ": ";
	cin >> i;
	i--;
	if (i >= 0 && i < length)
		return i;
	else {
		cerr << "Invalid Index." << endl;
		input_index(length, n);
	}
}
int input_index(int length) {
	int i;
	cout << "Input no. of rectangle: ";
	cin >> i;
	i--;
	if (i >= 0 && i < length)
		return i;
	else {
		cerr << "Invalid Index." << endl;
		input_index(length);
	}
}
void Move_demo(Rectangle* rectangles, int length) {
	Rectangle& selected_rectangle = rectangles[input_index(length)];
	try {
		selected_rectangle.info();
		double offset_x, offset_y;
		cout << "Input the offset:" << endl;
		cout << "offset x : ";
		cin >> offset_x;
		cout << "offset y : ";
		cin >> offset_y;
		selected_rectangle.offset(offset_x, offset_y);
		selected_rectangle.info();
	}
	catch (const char* err) {
		cerr << selected_rectangle.getDiagonal() << " " << err << endl;
		Move_demo(rectangles, length);
	}
}
void Intersect_demo(Rectangle* rectangles, int length) {
	Rectangle* selected_rectangle1, * selected_rectangle2;
	while (1) {
		selected_rectangle1 = &rectangles[input_index(length, 1)];
		try {
			selected_rectangle1->info();
			break;
		}
		catch (const char* err) {
			cerr << selected_rectangle1->getDiagonal() << " " << err << endl;
		}
	}
	while (1) {
		selected_rectangle2 = &rectangles[input_index(length, 2)];
		try {
			selected_rectangle2->info();
			break;
		}
		catch (const char* err) {
			cerr << selected_rectangle2->getDiagonal() << " " << err << endl;
		}
	}
	InterSectRect(*selected_rectangle1, *selected_rectangle2);
}

#define LENGTH 10
int main() {
	ifstream infile("rect.txt", ios::in);
	Rectangle rectangles[LENGTH];
	double a, b, c, d;
	for (int i = 0; i < LENGTH; i++) {
		infile >> a >> b >> c >> d;
		rectangles[i].setDiagonal(Line(Point(a, b), Point(c, d)));
	}
	/*--------------------------------------*/
	cout << "10 rectangles in arrRect£º" << endl;
	for (int i = 0; i < LENGTH; i++) {
		try {
			rectangles[i].info();
		}
		catch (const char* err) {
			cerr << rectangles[i].getDiagonal() << " " << err << endl;
		}
	}
	/*--------------------------------------*/
	cout << endl;
	cout << "Move a rectangle :" << endl;
	Move_demo(rectangles, LENGTH);
	Intersect_demo(rectangles, LENGTH);


	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
