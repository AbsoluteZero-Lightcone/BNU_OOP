#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "Shapes.h"

void data_format() {
    ifstream infile("shape.csv");
    ofstream outfile("shape.txt");
    char temp[50] = { 0 };
    char outtemp[50] = { 0 };
    do
    {
        for (int i = 0; i < 50; i++)
        {
            temp[i] = 0;
            outtemp[i] = 0;
        }
        infile.getline(temp, 49);
        for (int i = 0; i < strlen(temp); i++)
            if (temp[i] != ',')
                outtemp[i] = temp[i];
            else
                outtemp[i] = ' ';
        outfile << outtemp << endl;
    } while (!infile.eof());
    infile.close();
    outfile.close();
}

void input_from_fstream(ifstream& file, Shape* ptr_shape) {
    double t_dCenterX, t_dCenterY, t_dRadius;
    file >> t_dCenterX >> t_dCenterY >> t_dRadius;
    ptr_shape = new Circle(t_dCenterX, t_dCenterY, t_dRadius);
}

int main() {

    data_format();
    ifstream file("shape.txt", ios::in);
    int n;
    file >> n;
	Shape** ShapeArray;
    int* index;
    index = new int[n];
    ShapeArray = new Shape*[n];
    for (int i = 0; i < n; i++) {
        int cur_index;
        string type;
        file >>cur_index >>type;
        index[i] = cur_index;
        if (type == "circle") {
            double t_dCenterX, t_dCenterY, t_dRadius;
            file >> t_dCenterX >> t_dCenterY >> t_dRadius;
            ShapeArray[i] = new Circle(t_dCenterX, t_dCenterY, t_dRadius);
        }
        else if (type == "rectangle") {
            double t_dPointLeftTopX, t_dPointLeftTopY;
            double t_dPointRightBottomX,t_dPointRightBottomY;
            file >> t_dPointLeftTopX >> t_dPointLeftTopY;
                file >> t_dPointRightBottomX>>t_dPointRightBottomY;
            ShapeArray[i] = new Rectangle(
                t_dPointLeftTopX, t_dPointLeftTopY,
                t_dPointRightBottomX, t_dPointRightBottomY
            );

        }
        else if (type == "triangle") {
            double t_dPoint1X, t_dPoint1Y;
            double t_dPoint2X, t_dPoint2Y;
            double t_dPoint3X, t_dPoint3Y;
            file >> t_dPoint1X >> t_dPoint1Y;
            file >> t_dPoint2X >> t_dPoint2Y;
            file >> t_dPoint3X >> t_dPoint3Y;
            ShapeArray[i] = new Triangle(
                t_dPoint1X, t_dPoint1Y,
                t_dPoint2X, t_dPoint2Y,
                t_dPoint3X, t_dPoint3Y
            );
        }
    }
    for (int i = 0; i < n; i++) {
        ShapeArray[i]->GetInfo();
    }
	return 0;
}