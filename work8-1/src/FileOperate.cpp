/**
  ******************************************************************************
  * @file    FileOperate.cpp
  * @author  张亦法 202311998186
  * @date    2024-04-19
  * @brief   文件读写操作
  ******************************************************************************
  */
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void data_format() {
	ifstream infile(".\\res\\shape.csv", ios::in);
	ofstream outfile(".\\res\\shape.txt", ios::out);
	string temp;
	while (!infile.eof()) {
		getline(infile, temp);
		for (int i = 0; i < temp.length(); i++)
			if (temp[i] == ',')
				temp[i] = ' ';
		outfile << temp << endl;
	}
	infile.close();
	outfile.close();
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
