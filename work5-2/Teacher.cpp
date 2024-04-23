/**
  ******************************************************************************
  * @file    Teacher.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Teacher class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Teacher.h"

/* Constructors & Deconstructor --------------------------------------------- */
Teacher::Teacher() :
	m_strName("ȱʡ")
{}

Teacher::Teacher(string t_strName) :
	m_strName(t_strName)
{}

Teacher::Teacher(const Teacher& source) :
	m_strName(source.m_strName)
{}

Teacher::~Teacher() {}

/* Getters & Setters -------------------------------------------------------- */
string Teacher::get_strName()const { return m_strName; }
void Teacher::set_strName(string t_strName) { m_strName = t_strName; }

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
