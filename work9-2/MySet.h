/**
  ******************************************************************************
  * @file    MySet.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   MySet class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MYSET_H
#define __MYSET_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/* Constants -----------------------------------------------------------------*/
#define MAX_COUNT 100
/* Class ---------------------------------------------------------------------*/
class MySet
{
	int _array[MAX_COUNT];
	unsigned _count;
public:
	MySet(const MySet& source);
	void append(int n);

	MySet();												//(1)�޲ι��캯��
	friend istream& operator>>(istream&, MySet&);			//(2)������ʽ������
															//�����뼯����Ԫ�صĸ���n(n>0): 4 (�س�)
															//��������4��Ԫ�أ���Ҫ�ظ�����1 8 0 -2���س���
	friend ostream& operator<<(ostream&, const MySet&);		//(3)�����ʽ��(1,8,0,-2)
	const int& operator[](unsigned i)const;					//(4)�����±������
	bool IsInSet(int x) const;								//(5)�ж�����x�Ƿ񼯺��е�Ԫ��
	MySet operator+(const MySet&) const;					//(6)(1,8,0,-2) +(1,2,-5) = (1,8,0,-2,2,-5)
	MySet operator-(const MySet&) const;					//(7)(1,8,0,-2) - (1,2,-5) = (8,0,-2)
	MySet& operator++();									//(8)++(1,8,0,2) = (2,9,1,3)
	MySet operator++(int); 									//(9) (1,8,0,2) ++ = (2,9,1,3)
	friend MySet& operator--(MySet&);						//(10) --(1,8,0,2) = (0,7,-1,1)
	friend MySet operator--(MySet&, int); 					//(11) (1,8,0,2) -- = (0,7,-1,1)
};

/* Exported functions ------------------------------------------------------- */
MySet& operator--(MySet&);
MySet operator--(MySet&, int);
istream& operator>>(istream&, MySet&);
ostream& operator<<(ostream&, const MySet&);
#endif /* !__MYSET_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
