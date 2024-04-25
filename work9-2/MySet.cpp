/**
  ******************************************************************************
  * @file    MySet.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   MySet class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "MySet.h"

/* Constructors & Deconstructor --------------------------------------------- */
MySet::MySet():_count(0){}

/* Exported functions ------------------------------------------------------- */
int& MySet::operator[](unsigned i){}
bool MySet::IsInSet(int x) const{}
MySet MySet::operator+(const MySet&) const{}
MySet MySet::operator-(const MySet&) const{}
MySet& MySet::operator++(){}
MySet MySet::operator++(int){}

MySet& operator--(MySet&){}
MySet operator--(MySet&, int){}
istream& operator>>(istream&, MySet&){}
ostream& operator<<(ostream&, const MySet&){}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
