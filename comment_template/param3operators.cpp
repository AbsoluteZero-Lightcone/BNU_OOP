/**
  ******************************************************************************
  * @file    param3operators.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   param3operators class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "param3operators.h"

/* Constructors & Deconstructor --------------------------------------------- */
param3operators::param3operators() :
	m_dataname1(0),
	m_dataname2(0),
	m_dataname3(0)
{}

param3operators::param3operators(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3) :
	m_dataname1(t_dataname1),
	m_dataname2(t_dataname2),
	m_dataname3(t_dataname3)
{}

param3operators::param3operators(const param3operators& source) :
	m_dataname1(source.m_dataname1),
	m_dataname2(source.m_dataname2),
	m_dataname3(source.m_dataname3)
{}

param3operators::~param3operators() {}

/* Getters & Setters -------------------------------------------------------- */
datatype1 param3operators::get_dataname1()const { return m_dataname1; }
void param3operators::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 param3operators::get_dataname2()const { return m_dataname2; }
void param3operators::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }
datatype3 param3operators::get_dataname3()const { return m_dataname3; }
void param3operators::set_dataname3(datatype3 t_dataname3) { m_dataname3 = t_dataname3; }
void param3operators::set(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3) {
	m_dataname1 = t_dataname1; m_dataname2 = t_dataname2; m_dataname3 = t_dataname3;
}

/* Private functions -------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const param3operators& source : 待赋的值
  * @retval 无
  */
void param3operators::operator=(const param3operators& source) {
	m_dataname1 = source.m_dataname1;
	m_dataname2 = source.m_dataname2;
	m_dataname3 = source.m_dataname3;
}

/**
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void param3operators::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
param3operators& param3operators::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载前自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
param3operators& param3operators::operator++() {
	// todo
	return *this;
}

/**
  * @brief 类内重载前自减运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
param3operators& param3operators::operator--() {
	// todo
	return *this;
}
/**
  * @brief 类内重载后自增运算符
  * @param 无
  * @retval 值返回，不支持链式调用
  */
param3operators param3operators::operator++(int) {
	param3operators temp(*this);
	++(*this);
	return temp;
}

/**
  * @brief 类内重载后自减运算符
  * @param 无
  * @retval 值返回，不支持链式调用
  */
param3operators param3operators::operator--(int) {
	param3operators temp(*this);
	--(*this);
	return temp;
}

/**
  * @brief 类内重载取反运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
param3operators& param3operators::operator!() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const param3operators& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const param3operators& source) {
	// todo
	return out;
}

/**
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param param3operators& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
  */
istream& operator>>(istream& input, param3operators& target){
	cout << "input:";
	input
		>> target.m_dataname1
		>> target.m_dataname2;
	return input;
}

/**
  * @brief 重载大于运算符
  * @param const param3operators& n1 : 运算符左边的值
  * @param const param3operators& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const param3operators& n1, const param3operators& n2) {
	// todo
	return false;
}

/**
  * @brief 重载大于等于运算符
  * @param const param3operators& n1 : 运算符左边的值
  * @param const param3operators& n2 : 运算符右边的值
  * @retval bool, true for n1 >= n2
  */
bool operator>=(const param3operators& n1, const param3operators& n2) {
	return (n1 == n2) || (n1 > n2);
}

/**
  * @brief 重载小于运算符
  * @param const param3operators& n1 : 运算符左边的值
  * @param const param3operators& n2 : 运算符右边的值
  * @retval bool, true for n1 < n2
  */
bool operator<(const param3operators& n1, const param3operators& n2) {
	return !(n1 >= n2);
}

/**
  * @brief 重载小于等于运算符
  * @param const param3operators& n1 : 运算符左边的值
  * @param const param3operators& n2 : 运算符右边的值
  * @retval bool, true for n1 <= n2
  */
bool operator<=(const param3operators& n1, const param3operators& n2) {
	return !(n1 > n2);
}

/**
  * @brief 重载等于运算符
  * @param const param3operators& n1 : 运算符左边的值
  * @param const param3operators& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const param3operators& n1, const param3operators& n2) {
	if (n1.m_dataname1 != n2.m_dataname1)return false;
	if (n1.m_dataname2 != n2.m_dataname2)return false;
	if (n1.m_dataname3 != n2.m_dataname3)return false;
	return true;
}

/**
  * @brief 重载不等于运算符
  * @param const param3operators& n1 : 运算符左边的值
  * @param const param3operators& n2 : 运算符右边的值
  * @retval bool, true for n1 != n2
  */
bool operator!=(const param3operators& n1, const param3operators& n2) {
	if (n1.m_dataname1 == n2.m_dataname1)return false;
	if (n1.m_dataname2 == n2.m_dataname2)return false;
	if (n1.m_dataname3 == n2.m_dataname3)return false;
	return true;
}

/**
  * @brief 重载负号
  * @param param3operators n : 值传递待取反的值
  * @retval -n
  */
param3operators operator-(param3operators n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const param3operators& n1 : 加号左边的值
  * @param const param3operators& n2 : 加号右边的值
  * @retval n1 + n2
  */
param3operators operator+(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const param3operators& n1 : 被减数
  * @param const param3operators& n2 : 减数
  * @retval n1 - n2
  */
param3operators operator-(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/**
  * @brief 重载乘法运算符
  * @param const param3operators& n1 : 乘号左边的值
  * @param const param3operators& n2 : 乘号右边的值
  * @retval n1 * n2
  */
param3operators operator*(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/**
  * @brief 重载除法运算符
  * @param const param3operators& n1 : 被除数
  * @param const param3operators& n2 : 除数
  * @retval n1 / n2
  */
param3operators operator/(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
