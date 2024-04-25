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

	MySet();												//(1)无参构造函数
	friend istream& operator>>(istream&, MySet&);			//(2)输入形式举例：
															//请输入集合中元素的个数n(n>0): 4 (回车)
															//请输入这4个元素（不要重复）：1 8 0 -2（回车）
	friend ostream& operator<<(ostream&, const MySet&);		//(3)输出形式：(1,8,0,-2)
	const int& operator[](unsigned i)const;					//(4)重载下标运算符
	bool IsInSet(int x) const;								//(5)判定整数x是否集合中的元素
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
