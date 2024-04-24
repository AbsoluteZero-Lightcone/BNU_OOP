/**
  ******************************************************************************
  * @file    School.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   School class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "School.h"

/* Constructors & Deconstructor --------------------------------------------- */
School::School() :
	m_strName(0),
	m_strAddr(0)
{}

School::School(const char* t_strName,const char* t_strAddr) :
	m_strName(t_strName),
	m_strAddr(t_strAddr)
{}

School::School(const School& source) :
	m_strName(source.m_strName),
	m_strAddr(source.m_strAddr)
{}

School::~School() {}

/* Getters & Setters -------------------------------------------------------- */
char* School::get_strName()const { return m_strName; }
void School::set_strName(char* t_strName) { m_strName = t_strName; }
char* School::get_strAddr()const { return m_strAddr; }
void School::set_strAddr(char* t_strAddr) { m_strAddr = t_strAddr; }
void School::set(char* t_strName, char* t_strAddr) {
	m_strName = t_strName; m_strAddr = t_strAddr;
}

/* Exported functions ------------------------------------------------------- */


/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const School& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const School& source) {
	// todo
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
