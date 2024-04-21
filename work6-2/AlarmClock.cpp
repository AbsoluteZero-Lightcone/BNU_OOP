/**
  ******************************************************************************
  * @file    AlarmClock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   AlarmClock class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "AlarmClock.h"

/* Constructors & Deconstructor --------------------------------------------- */
AlarmClock::AlarmClock() :
	Clock(),
	m_nTargetHour(0),
	m_nTargetMinute(0)
{}

AlarmClock::AlarmClock(int t_nHour, int t_nMinute, int t_nSecond, int t_nTargetHour, int t_nTargetMinute) :
	Clock(t_nHour, t_nMinute, t_nSecond),
	m_nTargetHour(t_nTargetHour),
	m_nTargetMinute(t_nTargetMinute)
{}

AlarmClock::AlarmClock(const AlarmClock& source) :
	Clock(source),
	m_nTargetHour(source.m_nTargetHour),
	m_nTargetMinute(source.m_nTargetMinute)
{}

AlarmClock::~AlarmClock() {}

/* Getters & Setters -------------------------------------------------------- */
int AlarmClock::get_nTargetHour()const { return m_nTargetHour; }
void AlarmClock::set_nTargetHour(int t_nTargetHour) { m_nTargetHour = t_nTargetHour; }
int AlarmClock::get_nTargetMinute()const { return m_nTargetMinute; }
void AlarmClock::set_nTargetMinute(int t_nTargetMinute) { m_nTargetMinute = t_nTargetMinute; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const AlarmClock& source : ������ֵ
  * @retval ��
  */
void AlarmClock::operator=(const AlarmClock& source) {
	// todo
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void AlarmClock::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
AlarmClock& AlarmClock::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief �����������������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
AlarmClock& AlarmClock::operator++() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const AlarmClock& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const AlarmClock& source) {
	// todo
	return out;
}

/**
  * @brief ���ش��������
  * @param const AlarmClock& n1 : �������ߵ�ֵ
  * @param const AlarmClock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const AlarmClock& n1, const AlarmClock& n2) {
	// todo
	return false;
}

/**
  * @brief ���ص��������
  * @param const AlarmClock& n1 : �������ߵ�ֵ
  * @param const AlarmClock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const AlarmClock& n1, const AlarmClock& n2) {
	// todo
	return false;
}

/**
  * @brief ���ظ���
  * @param AlarmClock n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
AlarmClock operator-(AlarmClock n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const AlarmClock& n1 : �Ӻ���ߵ�ֵ
  * @param const AlarmClock& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
AlarmClock operator+(const AlarmClock& n1, const AlarmClock& n2) {
	AlarmClock temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const AlarmClock& n1 : ������
  * @param const AlarmClock& n2 : ����
  * @retval n1 - n2
  */
AlarmClock operator-(const AlarmClock& n1, const AlarmClock& n2) {
	AlarmClock temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
