/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
  * @date    2024-04-19
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "FileOperate.h"
#include "Shapes.h"
int main() {

	data_format();
	// 注意.csv文件的编码格式

	ifstream infile("res\\shape.txt", ios::in);
	if (!infile.is_open()) {
		cout << "File Error" << endl;
		return 1;
	}
	int n;
	infile >> n;

	Shape** ShapeArray;
	int* index;
	index = new int[n];
	ShapeArray = new Shape * [n];

	for (int i = 0; i < n; i++) {
		int cur_index;
		string type;
		infile >> cur_index >> type;
		index[i] = cur_index;
		if (type == "circle") {
			double t_dCenterX, t_dCenterY, t_dRadius;
			infile >> t_dCenterX >> t_dCenterY >> t_dRadius;
			ShapeArray[i] = new Circle(t_dCenterX, t_dCenterY, t_dRadius);
		}
		else if (type == "rectangle") {
			double t_dPointLeftTopX, t_dPointLeftTopY;
			double t_dPointRightBottomX, t_dPointRightBottomY;
			infile >> t_dPointLeftTopX >> t_dPointLeftTopY;
			infile >> t_dPointRightBottomX >> t_dPointRightBottomY;
			ShapeArray[i] = new Rectangle(
				t_dPointLeftTopX, t_dPointLeftTopY,
				t_dPointRightBottomX, t_dPointRightBottomY
			);
		}
		else if (type == "triangle") {
			double t_dPoint1X, t_dPoint1Y;
			double t_dPoint2X, t_dPoint2Y;
			double t_dPoint3X, t_dPoint3Y;
			infile >> t_dPoint1X >> t_dPoint1Y;
			infile >> t_dPoint2X >> t_dPoint2Y;
			infile >> t_dPoint3X >> t_dPoint3Y;
			ShapeArray[i] = new Triangle(
				t_dPoint1X, t_dPoint1Y,
				t_dPoint2X, t_dPoint2Y,
				t_dPoint3X, t_dPoint3Y
			);
		}
	}
	infile.close();

	double sum_area = 0.0, sum_perimeter = 0.0;
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << "形状" << index[i] << ":" << endl;
		ShapeArray[i]->GetInfo();
		sum_area += ShapeArray[i]->Area();
		sum_perimeter += ShapeArray[i]->Perimeter();
	}

	cout << endl;
	cout << "总面积是：" << sum_area << endl;
	cout << "总周长是：" << sum_perimeter << endl;


	for (int i = 0; i < n; i++)
		if (ShapeArray[i] != nullptr)
			delete ShapeArray[i], ShapeArray[i] = nullptr;

	if (ShapeArray != nullptr)
		delete[] ShapeArray, ShapeArray = nullptr;
	
	return 0;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
