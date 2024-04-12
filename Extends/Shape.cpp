#include "Shape.h"


#include <iostream>
using namespace std;


void Shape::GetInfo() const {
	cout << "这是一个";
	Show();
	cout << endl << "它的面积是" << Area();
	cout << endl << "它的周长是" << Perimeter();
}