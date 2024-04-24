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
#define _CRT_SECURE_NO_WARNINGS
/* Includes ------------------------------------------------------------------*/
#include "School.h"

/* Constructors & Deconstructor --------------------------------------------- */
School::School(const char* name, const char* addr) {
	m_strName = new char[80];
	m_strAddr = new char[80];
	strcpy(m_strName, name);
	strcpy(m_strAddr, addr);
	cout << "school constructed." << endl;
}
School::School(const School& source)
{
	m_strName = new char[80];
	m_strAddr = new char[80];
	strcpy(m_strName, source.m_strName);
	strcpy(m_strAddr, source.m_strAddr);
	cout << "school copy constructed." << endl;
}

School::~School() {
	if(m_strName)delete[] m_strName;
	if(m_strAddr)delete[] m_strAddr;
	cout << "school 	deconstructed. delete space of name and address." << endl;
}

/* Exported functions ------------------------------------------------------- */
void School::Show() const { cout << *this; }
/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const School& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const School& source) {
	out <<
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
