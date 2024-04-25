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
/**
  * @brief 无参构造函数，创建集合，将元素个数设为0.
  * @param None
  */
MySet::MySet() :_count(0) {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 重载下标运算符
  */
int& MySet::operator[](unsigned i){}

/**
  * @brief 判断整数x是否是集合的元素
  * @param int x
  * @retval bool
  */
bool MySet::IsInSet(int x) const{}

/**
  * @brief 两个集合对象的加法运算”+”，含义是合并两个集合
  * @param
  * @retval
  */
MySet MySet::operator+(const MySet& n2) const{}

/**
  * @brief 两个集合对象的减法运算”-”，含义是求出集合1中的不属于集合2的元素
	各操作的要求请参看程序注释。
  * @param
  * @retval
  */
MySet MySet::operator-(const MySet& n2) const{}

/**
  * @brief 集合的“前置++”运算，含义是将集合中的每一个元素自增1（前置自增）
  * @param
  * @retval
  */
MySet& MySet::operator++(){}
/**
  * @brief 集合的“后置++”运算，含义是将集合中的每一个元素自增1（后置自增）
  * @param
  * @retval
  */
MySet MySet::operator++(int){}
/**
  * @brief 友元：集合的“前置--”运算，含义是将集合中的每一个元素自减1（前置自减）
  * @param
  * @retval
  */
MySet& operator--(MySet& source){}
/**
  * @brief 友元：集合的“后置--”运算，含义是将集合中的每一个元素自减1（后置自减）
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
