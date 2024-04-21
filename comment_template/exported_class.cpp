/**
  ******************************************************************************
  * @file    exported_class.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   exported_class class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "exported_class.h"

/* Constructors & Deconstructor --------------------------------------------- */
exported_class::exported_class() :
	m_dataname1(0),
	m_dataname2(0)
{}

exported_class::exported_class(datatype1 t_dataname1, datatype2 t_dataname2) :
	m_dataname1(t_dataname1),
	m_dataname2(t_dataname2)
{}

exported_class::exported_class(const exported_class& source) :
	m_dataname1(source.m_dataname1),
	m_dataname2(source.m_dataname2)
{}

exported_class::~exported_class() {}

/* Getters & Setters -------------------------------------------------------- */
datatype1 exported_class::get_dataname1()const { return m_dataname1; }
void exported_class::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 exported_class::get_dataname2()const { return m_dataname2; }
void exported_class::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const exported_class& source : 待赋的值
  * @retval 无
  */
void exported_class::operator=(const exported_class& source) {
	// todo
}

/**
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void exported_class::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
exported_class& exported_class::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
exported_class& exported_class::operator++() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const exported_class& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const exported_class& source) {
	// todo
	return out;
}

/**
  * @brief 重载大于运算符
  * @param const exported_class& n1 : 运算符左边的值
  * @param const exported_class& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const exported_class& n1, const exported_class& n2) {
	// todo
	return false;
}

/**
  * @brief 重载等于运算符
  * @param const exported_class& n1 : 运算符左边的值
  * @param const exported_class& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const exported_class& n1, const exported_class& n2) {
	// todo
	return false;
}

/**
  * @brief 重载负号
  * @param exported_class n : 值传递待取反的值
  * @retval -n
  */
exported_class operator-(exported_class n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const exported_class& n1 : 加号左边的值
  * @param const exported_class& n2 : 加号右边的值
  * @retval n1 + n2
  */
exported_class operator+(const exported_class& n1, const exported_class& n2) {
	exported_class temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const exported_class& n1 : 被减数
  * @param const exported_class& n2 : 减数
  * @retval n1 - n2
  */
exported_class operator-(const exported_class& n1, const exported_class& n2) {
	exported_class temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
