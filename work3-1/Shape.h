#pragma once
#include "Point.h"
#include "Line.h"
#include "Rectangle.h"

class Shape {
public:
	virtual ~Shape() {}
	friend ostream& operator<<(ostream& out, const Shape& source);

};
ostream& operator<<(ostream& out, const Shape& source) {
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

class Empty :public Shape {

};