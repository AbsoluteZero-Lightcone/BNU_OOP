/**
  ******************************************************************************
  * @file    Fish.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
  * @date    2024-04-25
  * @brief   Fish class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Fish.h"

/* Static Members ------------------------------------------------------------*/
int Fish::s_nTotal = 0;
int Fish::s_nAlive = 0;
int Fish::s_nCurrentDay = 0;

/* Constructors & Deconstructor --------------------------------------------- */
Fish::Fish() :
	m_strName(""),
	m_strColor(""),
	m_nWeight(100),
	m_bAlive(1),
	m_nLastFedDey(0)
{
	s_nTotal++;
	s_nAlive++;
}

Fish::Fish(string t_strName, string t_strColor) :
	m_strName(t_strName),
	m_strColor(t_strColor),
	m_nWeight(100),
	m_bAlive(1),
	m_nLastFedDey(0)
{
	s_nTotal++;
	s_nAlive++;
}


Fish::~Fish() {}

/* Getters & Setters -------------------------------------------------------- */
string Fish::getName()const { return m_strName; }
string Fish::getColor()const { return m_strColor; }
int Fish::getWeight()const { return m_nWeight; }
int Fish::getLastFedDey()const { return m_nLastFedDey; }
bool Fish::isAlive()const { return m_bAlive; }

void Fish::set(string t_strName, string t_strColor) {
	m_strName = t_strName; m_strColor = t_strColor;
}


void Fish::nextDay() { s_nCurrentDay++; }
int Fish::getCurrentDay() { return s_nCurrentDay; }
int Fish::getTotal() { return s_nTotal; }
int Fish::getAlive() { return s_nAlive; }

/* Exported functions ------------------------------------------------------- */

/*
��ʳ��������10�ˡ�
���һ��������5��Բ���ʳ����ؾ�Ҫ����10�ˡ�
������ؼ��ٵ�0��ʱ����Ͷ����ˡ�
������س���300��ʱ����ͳ����ˡ�
*/
void Fish::update(bool isFed) {
	if (!m_bAlive)return;
	if (isFed) {
		m_nLastFedDey = s_nCurrentDay;
		m_nWeight += 10;
		if (m_nWeight >= 300) {
			m_bAlive = false;
			s_nAlive--;
		}
	}
	else {
		if (s_nCurrentDay - m_nLastFedDey >= 5) {
			m_nWeight -= 10;
			if (m_nWeight <= 0) {
				m_bAlive = false;
				s_nAlive--;
			}
		}
	}
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Fish& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Fish& source) {
	out << source.m_strName << "\t\t"
		<< source.m_strColor << "\t\t"
		<< source.m_nWeight << "g" << "\t\t";
	if (source.m_nLastFedDey)
		out << "��" << source.m_nLastFedDey << "��" << endl;
	else out << "��û�б�ι��" << endl;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
