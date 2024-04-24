/**
  ******************************************************************************
  * @file    Shape.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Shape class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Shapes.h"

/* Exported functions ------------------------------------------------------- */

ostream& operator<<(ostream& out, const Shape& source) {
	if (typeid(source) == typeid(Empty)) {
		const Empty& temp = dynamic_cast<Empty&>(const_cast<Shape&>(source));
		cout << "²»Ïà½»";
		return out;
	}
	if (typeid(source) == typeid(Point)) {
		const Point& temp = dynamic_cast<Point&>(const_cast<Shape&>(source));
		cout << "Point(" << temp.getX() << "," << temp.getY();
		return out;
	}
	if (typeid(source) == typeid(Line)) {
		const Line& temp = dynamic_cast<Line&>(const_cast<Shape&>(source));
		cout << "Line(" << temp.get_pointP1() << "," << temp.get_pointP2();
		return out;
	}
	if (typeid(source) == typeid(Rectangle)) {
		const Rectangle& temp = dynamic_cast<Rectangle&>(const_cast<Shape&>(source));
		cout << temp;
		return out;
	}
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
