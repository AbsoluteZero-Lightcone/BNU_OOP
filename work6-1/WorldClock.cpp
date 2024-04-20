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

// ���ұ��յ�ʹ��string()ռλ
string LUT_code[21] = { "ha","ak","la",string(),"ch","ny","dxy","bz","dxyz",string(),"ld","bl","ca","mo",string(),"nd",string(),"bk","bj","tk","sy" };
string LUT_name[21] = { "Hawaii","Alaska","LosAngeles",string(),"Chicago","NewYork","������ʱ��","Brazil","������-�в�",string(),"London","Berlin","Cario","Moscow",string(),"NewDelhi",string(),"Bangkok","Beijing","Tokyo","Sydney"};
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
  * @brief ��2��ʱ��ֵ�Ĳ��
  * @retval ע��ʱ�����ŵķ��򣺴�*thisʱ�̵�cʱ������Ҫ��ʱ�䣬��Ϊ����
  */
WorldClock WorldClock::Sub(const WorldClock& c) const {
	// ��ҵҪ��������WorldClock������ʵ�����㲻�ã�
	// 1.ʱ��Ĳ�ֵ��Ӧ���еص�
	// 2.WorldClock��������ʱ�̣�����ʱ�䣬ǿ���������������ͱ�ʾʱ��ξ�һ������ɳ���24Сʱ�Ĳ�����������⣬
	// �Ľ��ķ������������֣�
	// 1.�̳�Date�����ǲ�ͬ����
	// 2.����д��һ�����ڴ洢�����ʱ��ε�Time��
	// ���Ǿ������ʵ�־��Ȳ�д�ˣ�ʱ�����ޣ����������ҵҪ��
	return this->Clock::Sub(c).addHour((WorldClock::CityToRelativeHour(this->m_strCity) - WorldClock::CityToRelativeHour(c.m_strCity)));
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const WorldClock& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const WorldClock& source) {
	out << WorldClock::getCityName(source.m_strCity) << " " <<(Clock)source;
	return out;
}
/**
  * @brief ��ʾʱ�书��
  * @param None
  * @retval None
  */
void WorldClock::Show() const {
	cout << *this;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
