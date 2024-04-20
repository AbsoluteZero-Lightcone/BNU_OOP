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
#include <cmath>
#include <cstdint>
using namespace std;
#include "Clock.h"
/* Class ---------------------------------------------------------------------*/
class WorldClock:public Clock{
private:
	string m_strCity;
public:
	// Constructors & Deconstructor
	WorldClock();
	WorldClock(int t_nHour, int t_nMinute, int t_nSecond,string t_strCity="Beijing");
	WorldClock(const WorldClock& source);
	~WorldClock();

	// Getter & Setter
	string get_strCity();
	void set_strCity(string t_strCity);

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	friend ostream& operator<<(ostream& out, const WorldClock& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const WorldClock& source);

#endif /* !__WORLDCLOCK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
