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
int Fish::s_nCnt = 0;

/* Constructors & Deconstructor --------------------------------------------- */
Fish::Fish() :
	m_strName(""),
	m_strColor(""),
	m_nWeight(100)
{
	s_nCnt++;
}

Fish::Fish(string t_strName, string t_strColor) :
	m_strName(t_strName),
	m_strColor(t_strColor),
	m_nWeight(100)
{
	s_nCnt++;
}

Fish::Fish(const Fish& source) :
	m_strName(source.m_strName),
	m_strColor(source.m_strColor),
	m_nWeight(source.m_nWeight)
{
	s_nCnt++;
}

Fish::~Fish() { s_nCnt--; }

/* Getters & Setters -------------------------------------------------------- */
string Fish::get_strName()const { return m_strName; }
void Fish::set_strName(string t_strName) { m_strName = t_strName; }
string Fish::get_strColor()const { return m_strColor; }
void Fish::set_strColor(string t_strColor) { m_strColor = t_strColor; }
int Fish::get_nWeight()const { return m_nWeight; }
void Fish::set_nWeight(int t_nWeight) { m_nWeight = t_nWeight; }
void Fish::set(string t_strName, string t_strColor, int t_nWeight) {
	m_strName = t_strName; m_strColor = t_strColor; m_nWeight = t_nWeight;
}

/* Exported functions ------------------------------------------------------- */

void Fish::day(bool isfed) {

}

/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Fish& source : ������ֵ
  * @retval ��
  */
void Fish::operator=(const Fish& source) {
	m_strName = source.m_strName;
	m_strColor = source.m_strColor;
	m_nWeight = source.m_nWeight;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Fish& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Fish& source) {
	// todo
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
