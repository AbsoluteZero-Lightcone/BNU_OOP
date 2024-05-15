/**
  ******************************************************************************
  * @file    Person.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-15
  * @brief   Person class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Person.h"

/* Constructors & Deconstructor --------------------------------------------- */
Person::Person() :
	m_strName(""),
	m_nAge(0)
{}

Person::Person(string t_strName, int t_nAge) :
	m_strName(t_strName),
	m_nAge(t_nAge)
{}

Person::Person(const Person& source) :
	m_strName(source.m_strName),
	m_nAge(source.m_nAge)
{}

Person::~Person() {}

/* Getters & Setters -------------------------------------------------------- */
string Person::get_strName()const { return m_strName; }
void Person::set_strName(string t_strName) { m_strName = t_strName; }
int Person::get_nAge()const { return m_nAge; }
void Person::set_nAge(int t_nAge) { m_nAge = t_nAge; }
void Person::set(string t_strName, int t_nAge) {
	m_strName = t_strName; m_nAge = t_nAge;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Person& source : 待赋的值
  * @retval 无
  */
void Person::operator=(const Person& source) {
	m_strName = source.m_strName;
	m_nAge = source.m_nAge;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Person& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Person& source) {
	out << "Name: " << source.m_strName << ", Age: " << source.m_nAge;
	return out;
}

/**
  * @brief 重载等于运算符
  * @param const Person& n1 : 运算符左边的值
  * @param const Person& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Person& n1, const Person& n2) {
	if (n1.m_strName != n2.m_strName)return false;
	if (n1.m_nAge != n2.m_nAge)return false;
	return true;
}

/**
  * @brief 重载不等于运算符
  * @param const Person& n1 : 运算符左边的值
  * @param const Person& n2 : 运算符右边的值
  * @retval bool, true for n1 != n2
  */
bool operator!=(const Person& n1, const Person& n2) {
	if (n1.m_strName == n2.m_strName)return false;
	if (n1.m_nAge == n2.m_nAge)return false;
	return true;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
