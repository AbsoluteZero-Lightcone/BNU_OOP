/**
  ******************************************************************************
  * @file    Clock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
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

Clock::Clock(int t_nHour, int t_nMinute, int t_nSecond) {
	setTime(t_nHour, t_nMinute, t_nSecond);
}

Clock::Clock(const Clock& source) :
	m_nHour(source.m_nHour),
	m_nMinute(source.m_nMinute),
	m_nSecond(source.m_nSecond)
{}

Clock::~Clock() {}

/* Getters & Setters -------------------------------------------------------- */
int Clock::get_nHour()const { return m_nHour; }
void Clock::set_nHour(int t_nHour) {
	if (t_nHour >= 24 || t_nHour < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nHour = t_nHour;
}
int Clock::get_nMinute()const { return m_nMinute; }
void Clock::set_nMinute(int t_nMinute) {
	if (t_nMinute >= 60 || t_nMinute < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nMinute = t_nMinute;
}
int Clock::get_nSecond()const { return m_nSecond; }
void Clock::set_nSecond(int t_nSecond) {
	if (t_nSecond >= 60 || t_nSecond < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nSecond = t_nSecond;
}

void Clock::setTime(int t_nHour, int t_nMinute, int t_nSecond) {
	if (!isValid(t_nHour, t_nMinute, t_nSecond))
		Standarize(t_nHour, t_nMinute, t_nSecond);
	m_nHour = t_nHour;
	m_nMinute = t_nMinute;
	m_nSecond = t_nSecond;

}

// �涨����
/**
  * @brief ��ʾʱ�书��
  * @param None
  * @retval None
  */
void Clock::Show() const {
	cout << *this;
}

/**
  * @brief ��ʱ���ܣ�ÿһ��Tick��ʱ����ǰ��1��
  * @param None
  * @retval None
  */
void Clock::Tick() {
	(*this)++;
}

/**
  * @brief ��2��ʱ��ֵ�Ĳ��
  * @retval ע��ʱ�����ŵķ��򣺴�*thisʱ�̵�cʱ������Ҫ��ʱ�䣬��Ϊ����
  */
Clock Clock::Sub(const Clock& c) const {
	return Clock(c.m_nHour - m_nHour, c.m_nMinute - m_nMinute, c.m_nSecond - m_nSecond);
}

/**
  * @brief ����������ñ�׼�����ɽ��ܸ���ֵ
  * @retval ʹ�����ò�������
  */
void Standarize(int& t_nHour, int& t_nMinute, int& t_nSecond) {
	// work6�е�������������ɵ�ʱ������ֵ����ǿ�Ʊ�׼������ȫ��Ƿ�ѣ�
	// ������Clock���з�װ�ĳ�Ա����ֵ��setter�ϸ��������Ϊ�Ϸ�����������Ϊ��ֵ����Ҫ������ĸ���
	// ����Standardize������ʵ�ֺ���ҵҪ�����в�ͬ��
	// ���������� ��׼�������ʱ�����ԭʼ���ݣ������Ǳ�׼��Clock������Ϊ��������������ֶ���׼��
	int temp_h = t_nHour;
	int temp_m = t_nMinute;
	int temp_s = t_nSecond;
	t_nSecond = temp_s % 60;
	t_nMinute = (temp_m + temp_s / 60) % 60;
	t_nHour = (temp_h + (temp_m + temp_s / 60) / 60) % 24;
	// todo : �̳�Date�� �޸��ⲿ�֣���ʧ����Ľ�λ��
	// ������
	// ���������֤�� -23 -59 -59
	// ������߼���ȷ 
	if (t_nSecond < 0) {
		t_nSecond += 60;
		t_nMinute--;
	}
	if (t_nMinute < 0) {
		t_nMinute += 60;
		t_nHour--;
	}
	if (t_nHour < 0) {
		t_nHour += 24;
	}
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief ���϶�Ӧ�����������ı�����
  * @param n : ���ӵ��������ɽ��ܸ���
  * @retval Clock
  */
Clock Clock::addSecond(int n)const {
	Clock temp(*this);
	if (n >= 0)
		for (int i = 0; i < n; i++)
			temp++;
	else for (int i = 0; i < -n; i++)
		temp--;
	return temp;
}

/**
  * @brief ���϶�Ӧ��Сʱ��
  * @param n : ���ӵ�Сʱ�����ɽ��ܸ������ɿգ�Ĭ��Ϊ��һСʱ
  * @retval ������������ʵ����ʽ���
  */
Clock& Clock::toNextHour(int n) {
	m_nHour = (m_nHour + n) % 24;
	if (m_nHour < 0)m_nHour += 24;
	return *this;
}

/**
  * @brief �ж�ʱ���Ƿ���Ч
  * @param int t_nHour : ʱ
  * @param int t_nMinute : ��
  * @param int t_nSecond : �룬��ʡ
  * @retval bool 1 for ��Ч
  */
bool isValid(int t_nHour, int t_nMinute, int t_nSecond) {
	if (
		t_nHour >= 24 || t_nHour < 0 ||
		t_nMinute >= 60 || t_nMinute < 0 ||
		t_nSecond >= 60 || t_nSecond < 0
		)return 0;
	else return 1;
}

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
  * @brief �����������������������һ��
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
Clock& Clock::operator++() {
	m_nSecond++;
	if (m_nSecond == 60) {
		m_nSecond = 0;
		m_nMinute++;
		if (m_nMinute == 60) {
			m_nMinute = 0;
			m_nHour++;
			if (m_nHour == 24) {
				m_nHour = 0;
				// m_nDay++; //todo ��Date�м̳�
			}
		}
	}
	return *this;
}
Clock Clock::operator++(int) {
	Clock temp(*this);
	(*this)++;
	return temp;
}

/**
  * @brief ���������Լ������������һ��
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
Clock& Clock::operator--() {
	m_nSecond--;
	if (m_nSecond == -1) {
		m_nSecond = 59;
		m_nMinute--;
		if (m_nMinute == -1) {
			m_nMinute = 59;
			m_nHour--;
			if (m_nHour == -1) {
				m_nHour = 23;
				// m_nDay--; //todo ��Date�м̳�
			}
		}
	}
	return *this;
}
Clock Clock::operator--(int) {
	Clock temp(*this);
	(*this)--;
	return temp;
}

/**
  * @brief ���ش��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const Clock& n1, const Clock& n2) {
	return !(n1 <= n2);
}
/**
  * @brief ����С�������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 < n2
  */
bool operator<(const Clock& n1, const Clock& n2) {
	return !(n1 >= n2);
}

/**
  * @brief ���ش��ڵ��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 >= n2
  */
bool operator>=(const Clock& n1, const Clock& n2) {
	if (n1.m_nHour < n2.m_nHour)return false;
	else if (n1.m_nMinute < n2.m_nMinute)return false;
	else if (n1.m_nSecond < n2.m_nSecond)return false;
	else return true;
}
/**
  * @brief ����С�ڵ��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 <= n2
  */
bool operator<=(const Clock& n1, const Clock& n2) {
	return (n1 < n2) || (n1 == n2);
}

/**
  * @brief ���ص��������
  * @param const Clock& n1 : �������ߵ�ֵ
  * @param const Clock& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Clock& n1, const Clock& n2) {
	if (n1.m_nHour != n2.m_nHour)return false;
	else if (n1.m_nMinute != n2.m_nMinute)return false;
	else if (n1.m_nSecond != n2.m_nSecond)return false;
	return true;
}

/**
  * @brief ���ؼ����������ʱ������24Сʱ�����
  * @param const Clock& n1 : ������
  * @param const Clock& n2 : ����
  * @retval ʱ���
  */
Clock operator-(const Clock& n1, const Clock& n2) {
	// todo : �̳�Date��Ҫ�޸���Σ�����ͬ���ڿ��ǽ������������24Сʱ���������
	return Clock(
		n1.m_nHour - n2.m_nHour,
		n1.m_nMinute - n2.m_nMinute,
		n1.m_nSecond - n2.m_nSecond
	);
}

/**
  * @brief ��������+=����������϶�Ӧ������
  * @param c : Clock Object
  * @param n : ���ӵ�����
  * @retval ������������ʵ����ʽ���
  */
Clock operator+(Clock c, int n) {
	for (int i = 0; i < n; i++)
		c++;
	return c;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
