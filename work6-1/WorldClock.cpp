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

/* Datas ---------------------------------------------------------------------*/
// 查找表，空的使用string()占位
// 这里没必要用enum
// 也没必要写偏移量数组，用索引能表示出相对值就行
string LUT_code[REGION_COUNT] = { "ha","ak","la",string(),"ch","ny","dxy","bz","dxyz",string(),"ld","bl","ca","mo",string(),"nd",string(),"bk","bj","tk","sy" };
string LUT_name[REGION_COUNT] = { "Hawaii","Alaska","LosAngeles",string(),"Chicago","NewYork","大西洋时间","Brazil","大西洋-中部",string(),"London","Berlin","Cario","Moscow",string(),"NewDelhi",string(),"Bangkok","Beijing","Tokyo","Sydney" };

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
void WorldClock::set_strCity(string t_strCity) {
	if (t_strCity == string())return;// 合法性检查
	else if (isInArray(t_strCity, LUT_code, REGION_COUNT))
		m_strCity = t_strCity;
	else if (isInArray(t_strCity, LUT_name, REGION_COUNT))
		m_strCity = toRegionCode(t_strCity);
	// toRegionCode(string)可以返回Error
	// 但是已经检查过t_strCity存在于LUT中了，一定不会有Error的情况，此处不用写卫语句
	else return;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 判断元素在数组中是否存在
  * @param string s : 待查找的元素
  * @param string* arr : 数组
  * @param int length : 数组长度
  * @retval bool, 1 for 存在, 0 for 不存在
  */
bool isInArray(string s, string* arr,int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == s)return 1;
	}
	return 0;
}

/**
  * @brief 将时区转换成相对时间偏移量，非法输入返回-1
  * @param string region : 时区，可接受时区名或时区代码
  * @retval 相对时间偏移量
  */
int WorldClock::CityToRelativeHour(string region) {
	for (int i = 0; i < REGION_COUNT; i++) {
		if (LUT_code[i] == region || LUT_name[i] == region)
			return i;
	}
	return -1;
}

/**
  * @brief 将时区代码转换成时区名，非时区代码返回"Error"
  * @param string code : 时区代码
  * @retval 时区名
  */
string WorldClock::toRegionName(string code) {
	int index = -1;
	for (int i = 0; i < REGION_COUNT; i++) {
		if (LUT_code[i] == code) {
			index = i;
			break;
		}
	}
	if (index == -1)return "Error";
	return LUT_name[index];
}

/**
  * @brief 将时区名转换成时区代码，非时区名返回"Error"
  * @param string name : 时区名
  * @retval 时区代码
  */
string WorldClock::toRegionCode(string name) {
	int index = -1;
	for (int i = 0; i < REGION_COUNT; i++) {
		if (LUT_name[i] == name) {
			index = i;
			break;
		}
	}
	if (index == -1)return "Error";
	return LUT_code[index];
}

/**
  * @brief 时区转换
  * @param string target : 目的时区，可接受时区名或时区代码
  * @retval WorldClock对象
  */
WorldClock WorldClock::toRegion(string target) {
	WorldClock temp(*this);
	temp.addHour(
		WorldClock::CityToRelativeHour(target) -
		WorldClock::CityToRelativeHour(this->m_strCity)
	);
	temp.set_strCity(target);
	return temp;
}

/**
  * @brief 求2个时间值的差函数
  * @retval 注意时间流逝的方向：从*this时刻到c时刻所需要的时间，可为次日
  */
Clock WorldClock::Sub(const WorldClock& c) const {
	// 作业要求这里用WorldClock返回其实有两点不好：
	// 1.时间的差值不应带有地点，这里改进为返回Clock而非WorldClock
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
	out << WorldClock::toRegionName(source.m_strCity) << " " <<(Clock)source;
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
