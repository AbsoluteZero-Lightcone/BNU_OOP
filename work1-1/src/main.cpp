/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
using namespace std;
#include "Triangle.h"

int main() {
	Triangle t;
	while (1) {
		cout << "input 3 lengths: ";
		int a, b, c;
		cin >> a >> b >> c;
		try {
			t.SetLen(a, b, c);
			break;
		}
		catch (const char* err) {
			cerr << err << endl;
		}
	}
	cout << t;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
