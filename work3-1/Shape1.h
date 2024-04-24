#pragma once
//#include "Point.h"
//#include "Line.h"
//#include "Rectangle.h"

class Shape {
public:
	virtual ~Shape() {}
	friend ostream& operator<<(ostream& out, const Shape& source);

};

class Empty :public Shape {

};