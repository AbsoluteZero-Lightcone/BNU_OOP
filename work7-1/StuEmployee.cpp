/**
  ******************************************************************************
  * @file    StuEmployee.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   StuEmployee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "StuEmployee.h"

/* Constructors & Deconstructor --------------------------------------------- */
StuEmployee::StuEmployee() 
{}

StuEmployee::StuEmployee(const StuEmployee& source) 
{}

StuEmployee::~StuEmployee() {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const StuEmployee& source : 待赋的值
  * @retval 无
  */
void StuEmployee::operator=(const StuEmployee& source) {
	// todo
}

/**
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void StuEmployee::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
StuEmployee& StuEmployee::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
StuEmployee& StuEmployee::operator++() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const StuEmployee& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const StuEmployee& source) {
	// todo
	return out;
}

/**
  * @brief 重载大于运算符
  * @param const StuEmployee& n1 : 运算符左边的值
  * @param const StuEmployee& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const StuEmployee& n1, const StuEmployee& n2) {
	// todo
	return false;
}

/**
  * @brief 重载等于运算符
  * @param const StuEmployee& n1 : 运算符左边的值
  * @param const StuEmployee& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const StuEmployee& n1, const StuEmployee& n2) {
	// todo
	return false;
}

/**
  * @brief 重载负号
  * @param StuEmployee n : 值传递待取反的值
  * @retval -n
  */
StuEmployee operator-(StuEmployee n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const StuEmployee& n1 : 加号左边的值
  * @param const StuEmployee& n2 : 加号右边的值
  * @retval n1 + n2
  */
StuEmployee operator+(const StuEmployee& n1, const StuEmployee& n2) {
	StuEmployee temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const StuEmployee& n1 : 被减数
  * @param const StuEmployee& n2 : 减数
  * @retval n1 - n2
  */
StuEmployee operator-(const StuEmployee& n1, const StuEmployee& n2) {
	StuEmployee temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
