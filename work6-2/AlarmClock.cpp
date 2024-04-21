/**
  ******************************************************************************
  * @file    AlarmClock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   AlarmClock class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "AlarmClock.h"

/* Constructors & Deconstructor --------------------------------------------- */
AlarmClock::AlarmClock() :
	Clock(),
	m_nTargetHour(0),
	m_nTargetMinute(0)
{}

AlarmClock::AlarmClock(int t_nHour, int t_nMinute, int t_nSecond, int t_nTargetHour, int t_nTargetMinute) :
	Clock(t_nHour, t_nMinute, t_nSecond),
	m_nTargetHour(t_nTargetHour),
	m_nTargetMinute(t_nTargetMinute)
{}

AlarmClock::AlarmClock(const AlarmClock& source) :
	Clock(source),
	m_nTargetHour(source.m_nTargetHour),
	m_nTargetMinute(source.m_nTargetMinute)
{}

AlarmClock::~AlarmClock() {}

/* Getters & Setters -------------------------------------------------------- */
int AlarmClock::get_nTargetHour()const { return m_nTargetHour; }
void AlarmClock::set_nTargetHour(int t_nTargetHour) { m_nTargetHour = t_nTargetHour; }
int AlarmClock::get_nTargetMinute()const { return m_nTargetMinute; }
void AlarmClock::set_nTargetMinute(int t_nTargetMinute) { m_nTargetMinute = t_nTargetMinute; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const AlarmClock& source : 待赋的值
  * @retval 无
  */
void AlarmClock::operator=(const AlarmClock& source) {
	// todo
}

/**
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void AlarmClock::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
AlarmClock& AlarmClock::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
AlarmClock& AlarmClock::operator++() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const AlarmClock& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const AlarmClock& source) {
	// todo
	return out;
}

/**
  * @brief 重载大于运算符
  * @param const AlarmClock& n1 : 运算符左边的值
  * @param const AlarmClock& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const AlarmClock& n1, const AlarmClock& n2) {
	// todo
	return false;
}

/**
  * @brief 重载等于运算符
  * @param const AlarmClock& n1 : 运算符左边的值
  * @param const AlarmClock& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const AlarmClock& n1, const AlarmClock& n2) {
	// todo
	return false;
}

/**
  * @brief 重载负号
  * @param AlarmClock n : 值传递待取反的值
  * @retval -n
  */
AlarmClock operator-(AlarmClock n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const AlarmClock& n1 : 加号左边的值
  * @param const AlarmClock& n2 : 加号右边的值
  * @retval n1 + n2
  */
AlarmClock operator+(const AlarmClock& n1, const AlarmClock& n2) {
	AlarmClock temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const AlarmClock& n1 : 被减数
  * @param const AlarmClock& n2 : 减数
  * @retval n1 - n2
  */
AlarmClock operator-(const AlarmClock& n1, const AlarmClock& n2) {
	AlarmClock temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
