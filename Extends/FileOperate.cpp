/**
  ******************************************************************************
  * @file    FileOperate.cpp
  * @author  ���෨
  * @date    2024-04-19
  * @brief   �ļ���д����
  ******************************************************************************
  */
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void data_format() {
	ifstream infile("shape.csv", ios::in);
	ofstream outfile("shape.txt", ios::out);
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
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/