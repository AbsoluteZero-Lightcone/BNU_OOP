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

#define DIRECTION_UR // 坐标系方向宏定义
#include "demo.h"

#define LENGTH 10

int main() {
	/* 文件输入数据 -------------------------------------- */
	ifstream infile("rect.txt", ios::in);
	Rectangle rectangles[LENGTH];
	double a, b, c, d;
	for (int i = 0; i < LENGTH; i++) {
		infile >> a >> b >> c >> d;
		rectangles[i].setDiagonal(Diagonal(Point(a, b), Point(c, d)));
	}
	/* 展示所有矩形 -------------------------------------- */
	cout << "10 rectangles in arrRect：" << endl;
	for (int i = 0; i < LENGTH; i++) {
		try {
			rectangles[i].info();
		}
		catch (const char* err) {
			cerr << rectangles[i].getDiagonal() << " " << err << endl;
		}
	}
	/* 执行要求功能 -------------------------------------- */
	cout << endl << "Move a rectangle :" << endl;
	Move_demo(rectangles, LENGTH);
	cout << endl << "Judge 2 rectangles intersect:" << endl;
	Intersect_demo(rectangles, LENGTH);
	/*--------------------------------------*/
	return 0;
}

/********* Zhang Yifa | fabsolute Zero Studio - Lightcone *******END OF FILE****/
