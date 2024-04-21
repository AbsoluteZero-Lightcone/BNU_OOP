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

/* Datas ---------------------------------------------------------------------*/

#define REGION_COUNT 21
extern string LUT_code[REGION_COUNT];
extern string LUT_name[REGION_COUNT];

/* Class ---------------------------------------------------------------------*/
class WorldClock:public Clock{
private:
	string m_strCity;

	static int CityToRelativeHour(string city);
	static string toRegionName(string city);
	static string toRegionCode(string city);
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
	Clock Sub(const WorldClock& c) const;       //求2个时间值的差函数
	void Show() const;				            //显示时间功能
	WorldClock toRegion(string target);

	// 运算符重载
	friend ostream& operator<<(ostream& out, const WorldClock& source);
	friend Clock operator-(const WorldClock& n1, const WorldClock& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const WorldClock& source);
Clock operator-(const WorldClock& n1, const WorldClock& n2);
bool isInArray(string s, string* arr, int length);

#endif /* !__WORLDCLOCK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
