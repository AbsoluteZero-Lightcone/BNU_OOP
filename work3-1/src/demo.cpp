/**
  ******************************************************************************
  * @file    Demo.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Demo
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Demo.h"

/* Exported functions ------------------------------------------------------- */
int input_index(int length, int n) {
	int i;
	cout << "Input no. of rectangle" << n << ": ";
	cin >> i;
	i--;
	if (i >= 0 && i < length)
		return i;
	else {
		cerr << "Invalid Index." << endl;
		return input_index(length, n);
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
		return input_index(length);
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
	cout << *selected_rectangle1 << " intersect with " << *selected_rectangle2 << " at "
		<< InterSectRect(*selected_rectangle1, *selected_rectangle2);
}
/********* Zhang Yifa | fabsolute Zero Studio - Lightcone *******END OF FILE****/
