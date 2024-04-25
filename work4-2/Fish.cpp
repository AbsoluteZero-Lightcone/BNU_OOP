/**
  ******************************************************************************
  * @file    Fish.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
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
string Fish::getName()const{return m_strName;}
string Fish::getColor()const{return m_strColor;}
int Fish::getWeight()const{return m_nWeight;}
int Fish::getLastFedDey()const{return m_nLastFedDey;}
bool Fish::isAlive()const{return m_bAlive;}

void Fish::set(string t_strName, string t_strColor) {
	m_strName = t_strName; m_strColor = t_strColor;
}

/* Exported functions ------------------------------------------------------- */

void Fish::update(bool isfed) {
	if (!m_bAlive)return;

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
		<< source.m_nWeight << "g" << "\t\t"
		<< "第" << source.m_nLastFedDey << "天" << endl;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
