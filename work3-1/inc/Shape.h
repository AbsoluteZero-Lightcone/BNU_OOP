/**
  ******************************************************************************
  * @file    Shape.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-24
  * @brief   Shape class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SHAPE_H
#define __SHAPE_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Shape {
public:
	Shape(){}
	virtual ~Shape() {}
	friend ostream& operator<<(ostream& out, const Shape& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Shape& source);

#endif /* !__SHAPE_H */

/********* Zhang Yifa | fabsolute Zero Studio - Lightcone *******END OF FILE****/
