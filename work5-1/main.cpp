/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
using namespace std;
#include "Fraction.h"

bool isContinue() {
	string command;
	cout << "Continue?(y/n): ";
	cin >> command;
	if (command == "y" || command == "Y")
		return 1;
	else if (command == "n" || command == "N")
		return 0;
	else {
		cerr << "Invalid command." << endl;
		return isContinue();
	}
}

void demo() {
	do {
		int n, d;
		Fraction f1, f2;
		while (1) {
			cout << "Input f1: ";
			cin >> n >> d;
			try {
				f1.Set(n, d);
				break;
			}
			catch (const char* err) {
				cerr << err << endl;
			}
		}
		while (1) {
			cout << "Input f2: ";
			cin >> n >> d;
			try {
				f2.Set(n, d);
				break;
			}
			catch (const char* err) {
				cerr << err << endl;
			}
		}

		cout << f1 << " + " << f2 << " = " << f1 + f2 << endl;
		cout << f1 << " - " << f2 << " = " << f1 - f2 << endl;
		cout << f1 << " * " << f2 << " = " << f1 * f2 << endl;
		try {
			cout << f1 << " / " << f2 << " = " << f1 / f2 << endl;
		}
		catch (const char* err) {
			cerr << err << endl;
		}
	} while (isContinue());
}

int main() {
	demo();
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
