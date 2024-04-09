#include "Shapes.h"

#include <iostream>
using namespace std;

class Rectangle :public Shape {
private:
	Point m_pointLeftTop;
	Point m_pointRightBottom;
public:
	Rectangle() :m_pointLeftTop(0,0), m_pointRightBottom(0,0){

	}
	void Show()const {
		cout << "¾ØÐÎ" << endl;
	}
	double Area()const {
		cout << 0 << endl;
	}
	double Perimeter()const {
		cout << 0 << endl;
	}
};
class Triangle : public Shape {
private:
	double m_nX;
	double m_nY;
public:
	void Show()const {
		cout << "" << endl;
	}
	double Area() const {
		cout <<  << endl;
	}
	double Perimeter() const {
		cout << 0 << endl;
	}
};

int main() {

	return 0;
}