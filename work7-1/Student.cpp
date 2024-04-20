/**
  ******************************************************************************
  * @file    Student.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Student class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Student.h"

/* Constructors & Deconstructor --------------------------------------------- */
Student::Student(){}
Student::Student(const Student& source) {}
Student::~Student() {}

/* Getters & Setters -------------------------------------------------------- */
string Student::get_strMajor() { return m_strMajor; }
void Student::set_strMajor(string t_strMajor) { m_strMajor = t_strMajor; }
string Student::get_strStudentID() { return m_strStudentID; }
void Student::set_strStudentID(string t_strStudentID) { m_strStudentID = t_strStudentID; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Student& source : 待赋的值
  * @retval 无
  */
void Student::operator=(const Student& source) {
	// todo
}

/**
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void Student::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
Student& Student::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
Student& Student::operator++() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Student& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Student& source) {
	// todo
	return out;
}

/**
  * @brief 重载大于运算符
  * @param const Student& n1 : 运算符左边的值
  * @param const Student& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const Student& n1, const Student& n2) {
	// todo
	return false;
}

/**
  * @brief 重载等于运算符
  * @param const Student& n1 : 运算符左边的值
  * @param const Student& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Student& n1, const Student& n2) {
	// todo
	return false;
}

/**
  * @brief 重载负号
  * @param Student n : 值传递待取反的值
  * @retval -n
  */
Student operator-(Student n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const Student& n1 : 加号左边的值
  * @param const Student& n2 : 加号右边的值
  * @retval n1 + n2
  */
Student operator+(const Student& n1, const Student& n2) {
	Student temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const Student& n1 : 被减数
  * @param const Student& n2 : 减数
  * @retval n1 - n2
  */
Student operator-(const Student& n1, const Student& n2) {
	Student temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
