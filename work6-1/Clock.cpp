/**
  ******************************************************************************
  * @file    Clock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Clock class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Clock.h"

/* Constructors & Deconstructor --------------------------------------------- */
Clock::Clock() :
	m_nHour(0),
	m_nMinute(0),
	m_nSecond(0)
{}

Clock::Clock(int t_nHour, int t_nMinute, int t_nSecond) :
	m_nHour(t_nHour),
	m_nMinute(t_nMinute),
	m_nSecond(t_nSecond)
{}

Clock::Clock(const Clock& source) :
	m_nHour(source.m_nHour),
	m_nMinute(source.m_nMinute),
	m_nSecond(source.m_nSecond)
{}

Clock::~Clock() {}

/* Getters & Setters -------------------------------------------------------- */
int Clock::get_nHour() { return m_nHour; }
void Clock::set_nHour(int t_nHour) { m_nHour = t_nHour; }
int Clock::get_nMinute() { return m_nMinute; }
void Clock::set_nMinute(int t_nMinute) { m_nMinute = t_nMinute; }
int Clock::get_nSecond() { return m_nSecond; }
void Clock::set_nSecond(int t_nSecond) { m_nSecond = t_nSecond; }

void Clock::setTime(int t_nHour, int t_nMinute, int t_nSecond) {
	m_nHour = t_nHour;
	m_nMinute = t_nMinute;
	m_nSecond = t_nSecond;
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Clock& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Clock& source) {
	out << setw(2) << setfill('0') << source.m_nHour << ":"
		<< setw(2) << setfill('0') << source.m_nMinute << ":"
		<< setw(2) << setfill('0') << source.m_nSecond;
	return out;
}

/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Clock& source : 待赋的值
  * @retval 无
  */
void Clock::operator=(const Clock& source) {
	m_nHour = source.m_nHour;
	m_nMinute = source.m_nMinute;
	m_nSecond = source.m_nSecond;
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
Clock& Clock::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
Clock& Clock::operator++() {
	// todo
	return *this;
}

/**
  * @brief 重载大于运算符
  * @param const Clock& n1 : 运算符左边的值
  * @param const Clock& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const Clock& n1, const Clock& n2) {
	// todo
	return false;
}

/**
  * @brief 重载等于运算符
  * @param const Clock& n1 : 运算符左边的值
  * @param const Clock& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Clock& n1, const Clock& n2) {
	// todo
	return false;
}

/**
  * @brief 重载加法运算符
  * @param const Clock& n1 : 加号左边的值
  * @param const Clock& n2 : 加号右边的值
  * @retval n1 + n2
  */
Clock operator+(const Clock& n1, const Clock& n2) {
	Clock temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const Clock& n1 : 被减数
  * @param const Clock& n2 : 减数
  * @retval n1 - n2
  */
Clock operator-(const Clock& n1, const Clock& n2) {
	Clock temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
