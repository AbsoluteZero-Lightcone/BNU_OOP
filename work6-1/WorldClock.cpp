/**
  ******************************************************************************
  * @file    WorldClock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   WorldClock class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "WorldClock.h"

/* Constructors & Deconstructor --------------------------------------------- */
WorldClock::WorldClock() :
	Clock(0,0,0),
	m_strCity("Beijing")
{}

WorldClock::WorldClock(int t_nHour, int t_nMinute, int t_nSecond,string t_strCity):
	Clock(t_nHour, t_nMinute, t_nSecond),
	m_strCity(t_strCity)
{}

WorldClock::WorldClock(const WorldClock& source) :
	Clock(source),
	m_strCity(source.m_strCity)
{}

WorldClock::~WorldClock() {}

/* Getters & Setters -------------------------------------------------------- */
string WorldClock::get_strCity() { return m_strCity; }
void WorldClock::set_strCity(string t_strCity) { m_strCity = t_strCity; }

/* Exported functions ------------------------------------------------------- */

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const WorldClock& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const WorldClock& source) {
	out << source.m_strCity <<" " << source;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
