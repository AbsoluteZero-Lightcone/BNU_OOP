/**
  ******************************************************************************
  * @file    Clock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Clock class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Clock.h"

/* Constructors & Deconstructor --------------------------------------------- */
Clock::Clock() :
	m_nHour(0),
	m_nMinute(0),
	m_nSecond(0)
{}

Clock::Clock(int t_nHour, int t_nMinute, int t_nSecond) :
	m_nHour(t_nHour),
	m_nMinute(t_nMinute),
	m_nSecond(t_nSecond)
{}

Clock::Clock(const Clock& source) :
	m_nHour(source.m_nHour),
	m_nMinute(source.m_nMinute),
	m_nSecond(source.m_nSecond)
{}

Clock::~Clock() {}

/* Getters & Setters -------------------------------------------------------- */
int Clock::get_nHour() { return m_nHour; }
void Clock::set_nHour(int t_nHour) { m_nHour = t_nHour; }
int Clock::get_nMinute() { return m_nMinute; }
void Clock::set_nMinute(int t_nMinute) { m_nMinute = t_nMinute; }
int Clock::get_nSecond() { return m_nSecond; }
void Clock::set_nSecond(int t_nSecond) { m_nSecond = t_nSecond; }

void Clock::setTime(int t_nHour, int t_nMinute, int t_nSecond) {
	m_nHour = t_nHour;
	m_nMinute = t_nMinute;
	m_nSecond = t_nSecond;
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Clock& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Clock& source) {
	out << setw(2) << setfill('0') << source.m_nHour << ":"
		<< setw(2) << setfill('0') << source.m_nMinute << ":"
		<< setw(2) << setfill('0') << source.m_nSecond;
	return out;
}

/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Clock& source : ������ֵ
  * @retval ��
  */
void Clock::operator=(const Clock& source) {
	m_nHour = source.m_nHour;
	m_nMinute = source.m_nMinute;
	m_nSecond = source.m_nSecond;
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
Clock& Clock::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief �����������������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
Clock& Clock::operator++() {
	// todo
	return *this;
}

/**
  * @brief ���ش��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const Clock& n1, const Clock& n2) {
	// todo
	return false;
}

/**
  * @brief ���ص��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Clock& n1, const Clock& n2) {
	// todo
	return false;
}

/**
  * @brief ���ؼӷ������
  * @param const Clock& n1 : �Ӻ���ߵ�ֵ
  * @param const Clock& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
Clock operator+(const Clock& n1, const Clock& n2) {
	Clock temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const Clock& n1 : ������
  * @param const Clock& n2 : ����
  * @retval n1 - n2
  */
Clock operator-(const Clock& n1, const Clock& n2) {
	Clock temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
