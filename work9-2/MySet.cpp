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
MySet::MySet() :_count(0) {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief
  * @param
  * @retval
  */
int& MySet::operator[](unsigned i){}
/**
  * @brief
  * @param
  * @retval
  */
bool MySet::IsInSet(int x) const{}
/**
  * @brief
  * @param
  * @retval
  */
MySet MySet::operator+(const MySet& n2) const{}
/**
  * @brief
  * @param
  * @retval
  */
MySet MySet::operator-(const MySet& n2) const{}
/**
  * @brief
  * @param
  * @retval
  */
MySet& MySet::operator++(){}
/**
  * @brief
  * @param
  * @retval
  */
MySet MySet::operator++(int){}
/**
  * @brief
  * @param
  * @retval
  */
MySet& operator--(MySet& source){}
/**
  * @brief
  * @param
  * @retval
  */
MySet operator--(MySet& source, int){}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const MySet& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const MySet& source){
}
/**
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param MySet& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
  */
istream& operator>>(istream& input, MySet& target){
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
