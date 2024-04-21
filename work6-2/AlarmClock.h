/**
  ******************************************************************************
  * @file    AlarmClock.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
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
#include <cmath>
#include <cstdint>
using namespace std;
#include <Clock.h>

/* Class ---------------------------------------------------------------------*/
class AlarmClock :public Clock {
private:
	int m_nTargetHour;
	int m_nTargetMinute;
public:
	// Constructors & Deconstructor
	AlarmClock();
	AlarmClock(int t_nHour, int t_nMinute, int t_nSecond, int t_nTargetHour = 0, int t_nTargetMinute = 0);
	AlarmClock(const AlarmClock& source);
	~AlarmClock();

	// Getter & Setter
	int get_nTargetHour()const;
	void set_nTargetHour(int t_nTargetHour);
	int get_nTargetMinute()const;
	void set_nTargetMinute(int t_nTargetMinute);

	void setTargetTime();

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const AlarmClock& source);
	void operator=(int n);
	AlarmClock& operator+=(int n);
	AlarmClock& operator++();

	friend ostream& operator<<(ostream& out, const AlarmClock& source);
	friend bool operator>(const AlarmClock& n1, const AlarmClock& n2);
	friend bool operator==(const AlarmClock& n1, const AlarmClock& n2);
	friend AlarmClock operator-(AlarmClock n);
	friend AlarmClock operator+(const AlarmClock& n1, const AlarmClock& n2);
	friend AlarmClock operator-(const AlarmClock& n1, const AlarmClock& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const AlarmClock& source);
bool operator>(const AlarmClock& n1, const AlarmClock& n2);
bool operator==(const AlarmClock& n1, const AlarmClock& n2);
AlarmClock operator-(AlarmClock n);
AlarmClock operator+(const AlarmClock& n1, const AlarmClock& n2);
AlarmClock operator-(const AlarmClock& n1, const AlarmClock& n2);

#endif /* !__ALARMCLOCK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
