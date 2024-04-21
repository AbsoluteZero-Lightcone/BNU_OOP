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
// ���ұ��յ�ʹ��string()ռλ
// ����û��Ҫ��enum
// Ҳû��Ҫдƫ�������飬�������ܱ�ʾ�����ֵ����
string LUT_code[REGION_COUNT] = { "ha","ak","la",string(),"ch","ny","dxy","bz","dxyz",string(),"ld","bl","ca","mo",string(),"nd",string(),"bk","bj","tk","sy" };
string LUT_name[REGION_COUNT] = { "Hawaii","Alaska","LosAngeles",string(),"Chicago","NewYork","������ʱ��","Brazil","������-�в�",string(),"London","Berlin","Cario","Moscow",string(),"NewDelhi",string(),"Bangkok","Beijing","Tokyo","Sydney" };

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
	if (t_strCity == string())return;// �Ϸ��Լ��
	else if (isInArray(t_strCity, LUT_code, REGION_COUNT))
		m_strCity = t_strCity;
	else if (isInArray(t_strCity, LUT_name, REGION_COUNT))
		m_strCity = toRegionCode(t_strCity);
	// toRegionCode(string)���Է���Error
	// �����Ѿ�����t_strCity������LUT���ˣ�һ��������Error��������˴�����д�����
	else return;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief �ж�Ԫ�����������Ƿ����
  * @param string s : �����ҵ�Ԫ��
  * @param string* arr : ����
  * @param int length : ���鳤��
  * @retval bool, 1 for ����, 0 for ������
  */
bool isInArray(string s, string* arr,int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == s)return 1;
	}
	return 0;
}

/**
  * @brief ��ʱ��ת�������ʱ��ƫ�������Ƿ����뷵��-1
  * @param string region : ʱ�����ɽ���ʱ������ʱ������
  * @retval ���ʱ��ƫ����
  */
int WorldClock::CityToRelativeHour(string region) {
	for (int i = 0; i < REGION_COUNT; i++) {
		if (LUT_code[i] == region || LUT_name[i] == region)
			return i;
	}
	return -1;
}

/**
  * @brief ��ʱ������ת����ʱ��������ʱ�����뷵��"Error"
  * @param string code : ʱ������
  * @retval ʱ����
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
  * @brief ��ʱ����ת����ʱ�����룬��ʱ��������"Error"
  * @param string name : ʱ����
  * @retval ʱ������
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
  * @brief ʱ��ת��
  * @param string target : Ŀ��ʱ�����ɽ���ʱ������ʱ������
  * @retval WorldClock����
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
  * @brief ��2��ʱ��ֵ�Ĳ��
  * @retval ע��ʱ�����ŵķ��򣺴�*thisʱ�̵�cʱ������Ҫ��ʱ�䣬��Ϊ����
  */
Clock WorldClock::Sub(const WorldClock& c) const {
	// ��ҵҪ��������WorldClock������ʵ�����㲻�ã�
	// 1.ʱ��Ĳ�ֵ��Ӧ���еص㣬����Ľ�Ϊ����Clock����WorldClock
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
	out << WorldClock::toRegionName(source.m_strCity) << " " <<(Clock)source;
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
