/**
  ******************************************************************************
  * @file    AlarmClock.h
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
  * @date    2024-04-21
  * @brief   AlarmClock class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ALARMCLOCK_H
#define __ALARMCLOCK_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "Clock.h"

/* Class ---------------------------------------------------------------------*/
class AlarmClock :public Clock {
private:
	void Alarm();
public:

	Clock AlarmTime;// Clock 内部已经经过封装，直接对外公开不会有安全问题

	// Constructors & Deconstructor
	AlarmClock();
	AlarmClock(int t_nHour, int t_nMinute, int t_nSecond, int t_nTargetHour = 0, int t_nTargetMinute = 0);
	AlarmClock(const AlarmClock& source);
	~AlarmClock();

	// Getter & Setter
	void setAlarmTime(int t_nTargetHour, int t_nTargetMinute);

	// 规定动作
	void Tick();

	// 运算符重载
	friend ostream& operator<<(ostream& out, const AlarmClock& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const AlarmClock& source);

#endif /* !__ALARMCLOCK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
