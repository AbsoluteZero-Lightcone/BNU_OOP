/**
  ******************************************************************************
  * @file    AlarmClock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-21
  * @brief   AlarmClock class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "AlarmClock.h"

/* Constructors & Deconstructor --------------------------------------------- */
AlarmClock::AlarmClock() :
	Clock(),
	AlarmTime()
{}

AlarmClock::AlarmClock(int t_nHour, int t_nMinute, int t_nSecond, int t_nTargetHour, int t_nTargetMinute) :
	Clock(t_nHour, t_nMinute, t_nSecond), 
	AlarmTime(t_nTargetHour, t_nTargetMinute,0)
{}

AlarmClock::AlarmClock(const AlarmClock& source) :
	Clock(source),
	AlarmTime(source.AlarmTime)
{}

AlarmClock::~AlarmClock() {}

/* Getters & Setters -------------------------------------------------------- */

void AlarmClock::setAlarmTime(int t_nTargetHour, int t_nTargetMinute) {
	AlarmTime.setTime(t_nTargetHour, t_nTargetMinute, 0);
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief 走字儿
  * @param None
  * @retval None
  */
void AlarmClock::Tick() {
	(*this)++;
	if ((*this) >= AlarmTime &&  (*this) < AlarmTime.addSecond(10))// 响铃10秒
		Alarm();
}

/**
  * @brief 响铃，私有成员函数
  * @param None
  * @retval None
  */
void AlarmClock::Alarm() {
	cout << '\7' ;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const AlarmClock& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const AlarmClock& source) {
	out << (Clock)source;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
