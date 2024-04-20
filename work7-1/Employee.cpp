/**
  ******************************************************************************
  * @file    Employee.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Employee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Employee.h"

/* Constructors & Deconstructor --------------------------------------------- */
Employee::Employee() :
	m_strDepartment(0),
	m_strEmployeeID(0)
{}

Employee::Employee(string t_strDepartment, string t_strEmployeeID):
	m_strDepartment(t_strDepartment), 
	m_strEmployeeID(t_strEmployeeID)
{}

Employee::Employee(const Employee& source) :
	m_strDepartment(source.m_strDepartment),
	m_strEmployeeID(source.m_strEmployeeID)
{}

Employee::~Employee() {}

/* Getters & Setters -------------------------------------------------------- */
string Employee::get_strDepartment() { return m_strDepartment; }
void Employee::set_strDepartment(string t_strDepartment) { m_strDepartment = t_strDepartment; }
string Employee::get_strEmployeeID() { return m_strEmployeeID; }
void Employee::set_strEmployeeID(string t_strEmployeeID) { m_strEmployeeID = t_strEmployeeID; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Employee& source : 待赋的值
  * @retval 无
  */
void Employee::operator=(const Employee& source) {
	// todo
}

/**
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void Employee::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
Employee& Employee::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
Employee& Employee::operator++() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Employee& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Employee& source) {
	// todo
	return out;
}

/**
  * @brief 重载大于运算符
  * @param const Employee& n1 : 运算符左边的值
  * @param const Employee& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const Employee& n1, const Employee& n2) {
	// todo
	return false;
}

/**
  * @brief 重载等于运算符
  * @param const Employee& n1 : 运算符左边的值
  * @param const Employee& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Employee& n1, const Employee& n2) {
	// todo
	return false;
}

/**
  * @brief 重载负号
  * @param Employee n : 值传递待取反的值
  * @retval -n
  */
Employee operator-(Employee n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const Employee& n1 : 加号左边的值
  * @param const Employee& n2 : 加号右边的值
  * @retval n1 + n2
  */
Employee operator+(const Employee& n1, const Employee& n2) {
	Employee temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const Employee& n1 : 被减数
  * @param const Employee& n2 : 减数
  * @retval n1 - n2
  */
Employee operator-(const Employee& n1, const Employee& n2) {
	Employee temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
