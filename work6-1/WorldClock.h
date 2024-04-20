/**
  ******************************************************************************
  * @file    WorldClock.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   WorldClock class
  * @encode  GB2312
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WORLDCLOCK_H
#define __WORLDCLOCK_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "Clock.h"
/* Class ---------------------------------------------------------------------*/
class WorldClock:public Clock{
private:
	string m_strCity;

	static int CityToRelativeHour(string city);
	static string getCityName(string city);
public:
	// Constructors & Deconstructor
	WorldClock();
	WorldClock(int t_nHour, int t_nMinute, int t_nSecond,string t_strCity="bj");
	WorldClock(const WorldClock& source);
	WorldClock(const Clock& source);

	~WorldClock();

	// Getter & Setter
	string get_strCity();
	void set_strCity(string t_strCity);

	// 规定动作
	WorldClock Sub(const WorldClock& c) const;

	// 运算符重载
	friend ostream& operator<<(ostream& out, const WorldClock& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const WorldClock& source);

#endif /* !__WORLDCLOCK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
