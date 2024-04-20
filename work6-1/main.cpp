/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;
#include "WorldClock.h"

int main() {
	WorldClock c(1,2,3);
	c.setTime(5, 6, 7);
	cout << c << endl;
	c.Tick();
	c.Show();
	cout << endl;
	cout << c.Sub(Clock(1, 2, 3)) << endl;
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
