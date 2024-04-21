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
  * @brief ���ֶ�
  * @param None
  * @retval None
  */
void AlarmClock::Tick() {
	(*this)++;
	if ((*this) >= AlarmTime &&  (*this) < AlarmTime.addSecond(10))// ����10��
		Alarm();
}

/**
  * @brief ���壬˽�г�Ա����
  * @param None
  * @retval None
  */
void AlarmClock::Alarm() {
	cout << '\7' ;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const AlarmClock& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const AlarmClock& source) {
	out << (Clock)source;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
