#ifndef __RECTANGLE_H
#include <iostream>
using namespace std;

class Rectangle :public Shape {
private:
	Point m_pointLeftTop;
	Point m_pointRightBottom;
public:
	Rectangle() :
		m_pointLeftTop(0, 1),
		m_pointRightBottom(1, 0) 
	{}
	Rectangle(
		double t_dPointLeftTopX, double t_dPointLeftTopY,
		double t_dPointRightBottomX, double t_dPointRightBottomY
	) :
		m_pointLeftTop(t_dPointLeftTopX, t_dPointLeftTopY),
		m_pointRightBottom(t_dPointRightBottomX, t_dPointRightBottomY)
	{}
	~Rectangle() {}
	void Show()const {
		cout << "¾ØÐÎ" << endl;
	}
	double Area()const {
		return 0;
	}
	double Perimeter()const {
		return 0;
	}
};
#endif // !__RECTANGLE_H
