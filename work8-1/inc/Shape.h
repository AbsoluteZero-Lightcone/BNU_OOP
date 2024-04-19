/**
  ******************************************************************************
  * @file    Shape.h
  * @author  张亦法
  * @date    2024-04-19
  * @brief   Shape 基类
  ******************************************************************************
  */
#ifndef __SHAPE_H
#define __SHAPE_H

#include <iostream>
using namespace std;

class Shape
{
public:

	Shape() {}
	virtual ~Shape() {}

	void GetInfo() const {
		cout << "这是一个";
		Show();
		cout << "它的面积是" << Area() << endl;
		cout << "它的周长是" << Perimeter() << endl;
	}
	virtual void Show()const = 0;
	virtual double Area()const = 0;
	virtual double Perimeter()const = 0;

};

#endif // !__SHAPE_H

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
