/**
  ******************************************************************************
  * @file    StuEmployee.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   StuEmployee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STUEMPLOYEE_H
#define __STUEMPLOYEE_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class StuEmployee {
private:
public:
	// Constructors & Deconstructor
	StuEmployee();
	StuEmployee(const StuEmployee& source);
	~StuEmployee();


	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const StuEmployee& source);
	void operator=(int n);
	StuEmployee& operator+=(int n);
	StuEmployee& operator++();
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const StuEmployee& source);
bool operator>(const StuEmployee& n1, const StuEmployee& n2);
bool operator==(const StuEmployee& n1, const StuEmployee& n2);
StuEmployee operator-(StuEmployee n);
StuEmployee operator+(const StuEmployee& n1, const StuEmployee& n2);
StuEmployee operator-(const StuEmployee& n1, const StuEmployee& n2);

#endif /* !__STUEMPLOYEE_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
