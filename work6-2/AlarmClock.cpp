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
{
	try { setTargetTime(t_nTargetHour, t_nTargetMinute); }
	catch (string info) {
		cout << info << endl;
		// 当输入的值非法时使用默认值：
		setTargetTime(0, 0);
	}
}

AlarmClock::AlarmClock(const AlarmClock& source) :
	Clock(source)
{
	setTargetTime(source.m_nTargetHour, source.m_nTargetMinute);
}

AlarmClock::~AlarmClock() {}

/* Getters & Setters -------------------------------------------------------- */
int AlarmClock::get_nTargetHour()const { return m_nTargetHour; }
void AlarmClock::set_nTargetHour(int t_nTargetHour) {
	if (t_nTargetHour >= 24 || t_nTargetHour < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nTargetHour = t_nTargetHour;
}
int AlarmClock::get_nTargetMinute()const { return m_nTargetMinute; }
void AlarmClock::set_nTargetMinute(int t_nTargetMinute) {
	if (t_nTargetMinute >= 60 || t_nTargetMinute < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nTargetMinute = t_nTargetMinute;
}

void AlarmClock::setTargetTime(int t_nTargetHour, int t_nTargetMinute) {
	if (!isValid(t_nTargetHour, t_nTargetMinute)) {
		throw("Incorrect Time Format.");
		return;
	}
	m_nTargetHour=t_nTargetHour;
	m_nTargetMinute=t_nTargetMinute;
}

/* Exported functions ------------------------------------------------------- */

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
