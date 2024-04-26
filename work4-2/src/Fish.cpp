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
吃食后，鱼增长10克。
如果一条鱼连续5天吃不到食物，体重就要减少10克。
鱼的体重减少到0克时，鱼就饿死了。
鱼的体重长到300克时，鱼就撑死了。
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
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Fish& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Fish& source) {
	out << source.m_strName << "\t\t"
		<< source.m_strColor << "\t\t"
		<< source.m_nWeight << "g" << "\t\t";
	if (source.m_nLastFedDey)
		out << "第" << source.m_nLastFedDey << "天" << endl;
	else out << "还没有被喂过" << endl;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
