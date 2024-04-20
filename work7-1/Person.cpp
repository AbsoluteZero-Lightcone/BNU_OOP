/**
  ******************************************************************************
  * @file    Person.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Person class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Person.h"

/* Constructors & Deconstructor --------------------------------------------- */
Person::Person() :
	m_strName(0),
	m_nAge(0)
{}

Person::Person(string t_strName, int t_nAge):
	m_strName(t_strName), 
	m_nAge(t_nAge)
{}

Person::Person(const Person& source) :
	m_strName(source.m_strName),
	m_nAge(source.m_nAge)
{}

Person::~Person() {}

/* Getters & Setters -------------------------------------------------------- */
string Person::get_strName() { return m_strName; }
void Person::set_strName(string t_strName) { m_strName = t_strName; }
int Person::get_nAge() { return m_nAge; }
void Person::set_nAge(int t_nAge) { m_nAge = t_nAge; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Person& source : 待赋的值
  * @retval 无
  */
void Person::operator=(const Person& source) {
	// todo
}

/**
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void Person::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
Person& Person::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
Person& Person::operator++() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Person& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Person& source) {
	// todo
	return out;
}

/**
  * @brief 重载大于运算符
  * @param const Person& n1 : 运算符左边的值
  * @param const Person& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const Person& n1, const Person& n2) {
	// todo
	return false;
}

/**
  * @brief 重载等于运算符
  * @param const Person& n1 : 运算符左边的值
  * @param const Person& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Person& n1, const Person& n2) {
	// todo
	return false;
}

/**
  * @brief 重载负号
  * @param Person n : 值传递待取反的值
  * @retval -n
  */
Person operator-(Person n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const Person& n1 : 加号左边的值
  * @param const Person& n2 : 加号右边的值
  * @retval n1 + n2
  */
Person operator+(const Person& n1, const Person& n2) {
	Person temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const Person& n1 : 被减数
  * @param const Person& n2 : 减数
  * @retval n1 - n2
  */
Person operator-(const Person& n1, const Person& n2) {
	Person temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
