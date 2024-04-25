/**
  ******************************************************************************
  * @file    RMB.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   RMB class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RMB_H
#define __RMB_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class RMB {
private:
	char m_chSign;
	unsigned int m_nYuan;
	unsigned int m_nJiao;
	unsigned int m_nFen;


public:
	// Constructors & Deconstructor
	RMB();
	RMB(const RMB& source);
	~RMB();

	void operator=(const RMB& source);
	void operator=(int n);
	RMB& operator+=(int n);
	RMB& operator++();
	RMB& operator--();
	RMB operator++(int);
	RMB operator--(int);
	RMB& operator!();

	friend ostream& operator<<(ostream& out, const RMB& source);
	friend istream& operator>>(istream& input, RMB& target);
	friend bool operator>(const RMB& n1, const RMB& n2);
	friend bool operator<(const RMB& n1, const RMB& n2);
	friend bool operator>=(const RMB& n1, const RMB& n2);
	friend bool operator<=(const RMB& n1, const RMB& n2);
	friend bool operator==(const RMB& n1, const RMB& n2);
	friend bool operator!=(const RMB& n1, const RMB& n2);
	friend RMB operator-(RMB n);
	friend RMB operator+(const RMB& n1, const RMB& n2);
	friend RMB operator-(const RMB& n1, const RMB& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const RMB& source);
istream& operator>>(istream& input, RMB& target);
bool operator>(const RMB& n1, const RMB& n2);
bool operator<(const RMB& n1, const RMB& n2);
bool operator>=(const RMB& n1, const RMB& n2);
bool operator<=(const RMB& n1, const RMB& n2);
bool operator==(const RMB& n1, const RMB& n2);
bool operator!=(const RMB& n1, const RMB& n2);
RMB operator-(RMB n);
RMB operator+(const RMB& n1, const RMB& n2);
RMB operator-(const RMB& n1, const RMB& n2);

#endif /* !__RMB_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
