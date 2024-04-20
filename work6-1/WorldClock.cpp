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
	Clock(0, 0, 0),
	m_strCity("bj")
{}

WorldClock::WorldClock(int t_nHour, int t_nMinute, int t_nSecond, string t_strCity) :
	Clock(t_nHour, t_nMinute, t_nSecond),
	m_strCity(t_strCity)
{}

WorldClock::WorldClock(const WorldClock& source) :
	Clock(source),
	m_strCity(source.m_strCity)
{}

WorldClock::WorldClock(const Clock& source) :
	Clock(source),
	m_strCity("bj")
{}

WorldClock::~WorldClock() {}

/* Getters & Setters -------------------------------------------------------- */
string WorldClock::get_strCity() { return m_strCity; }
void WorldClock::set_strCity(string t_strCity) { m_strCity = t_strCity; }

/* Exported functions ------------------------------------------------------- */

// 查找表，空的使用string()占位
string LUT_code[21] = { "ha","ak","la",string(),"ch","ny","dxy","bz","dxyz",string(),"ld","bl","ca","mo",string(),"nd",string(),"bk","bj","tk","sy" };
string LUT_name[21] = { "Hawaii","Alaska","LosAngeles",string(),"Chicago","NewYork","大西洋时间","Brazil","大西洋-中部",string(),"London","Berlin","Cario","Moscow",string(),"NewDelhi",string(),"Bangkok","Beijing","Tokyo","Sydney"};
int WorldClock::CityToRelativeHour(string city) {
	for (int i = 0; i < 21; i++) {
		if (LUT_code[i] == city)
			return i;
	}
	return -1;
}

string WorldClock::getCityName(string city) {
	int index = -1;
	for (int i = 0; i < 21; i++) {
		if (LUT_code[i] == city) {
			index = i;
			break;
		}
	}
	if (index == -1)return "Error";
	return LUT_name[index];
}

/**
  * @brief 求2个时间值的差函数
  * @retval 注意时间流逝的方向：从*this时刻到c时刻所需要的时间，可为次日
  */
WorldClock WorldClock::Sub(const WorldClock& c) const {
	// 作业要求这里用WorldClock返回其实有两点不好：
	// 1.时间的差值不应带有地点
	// 2.WorldClock表征的是时刻，而非时间，强行用这种数据类型表示时间段就一定会造成超过24小时的部分溢出的问题，
	// 改进的方法可以有两种：
	// 1.继承Date，考虑不同日期
	// 2.重新写另一个用于存储与表征时间段的Time类
	// 但是具体程序实现就先不写了，时间有限，就先完成作业要求
	return this->Clock::Sub(c).addHour((WorldClock::CityToRelativeHour(this->m_strCity) - WorldClock::CityToRelativeHour(c.m_strCity)));
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const WorldClock& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const WorldClock& source) {
	out << WorldClock::getCityName(source.m_strCity) << " " <<(Clock)source;
	return out;
}
/**
  * @brief 显示时间功能
  * @param None
  * @retval None
  */
void WorldClock::Show() const {
	cout << *this;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
