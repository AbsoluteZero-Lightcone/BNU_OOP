/**
  ******************************************************************************
  * @file    Demo.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Demo
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEMO_H
#define __DEMO_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Shapes.h"

/* Exported functions ------------------------------------------------------- */
int input_index(int length, int n);
int input_index(int length);
void Move_demo(Rectangle* rectangles, int length);
void Intersect_demo(Rectangle* rectangles, int length);

#endif /* !__DEMO_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
