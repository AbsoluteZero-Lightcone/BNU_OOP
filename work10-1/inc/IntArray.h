/**
  ******************************************************************************
  * @file    IntArray.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-13
  * @brief   IntArray class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __INTARRAY_H
#define __INTARRAY_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class IntArray {
private:
	int m_nSize;
	int* m_ptrData;
public:
	// Constructors & Deconstructor
	IntArray(int t_nSize);
	IntArray(const IntArray& source);
	~IntArray();

	// Getter & Setter
	int size() const;
	void resize(int t_nSize);
	int& operator[](int index);

	void operator=(const IntArray& source);

	// Friend functions
	friend ostream& operator<<(ostream& out, const IntArray& source);
	friend istream& operator>>(istream& input, IntArray& target);

	friend bool operator==(const IntArray& a, const IntArray& b);
	friend bool operator!=(const IntArray& a, const IntArray& b);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const IntArray& source);
istream& operator>>(istream& input, IntArray& target);
bool operator==(const IntArray& a, const IntArray& b);
bool operator!=(const IntArray& a, const IntArray& b);
#endif /* !__INTARRAY_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
