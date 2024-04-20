/**
  ******************************************************************************
  * @file    Person.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Person class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Person.h"

/* Constructors & Deconstructor --------------------------------------------- */
Person::Person() :
	m_strName("ȱʡ"),
	m_nAge(0)
{}

Person::Person(string t_strName, int t_nAge):
	m_strName(t_strName), 
	m_nAge(t_nAge)
{}

Person::Person(const Person& source) :
	m_strName(source.m_strName),
	m_nAge(source.m_nAge)
{}

Person::~Person() {}

/* Getters & Setters -------------------------------------------------------- */
string Person::get_strName() { return m_strName; }
void Person::set_strName(string t_strName) { m_strName = t_strName; }
int Person::get_nAge() { return m_nAge; }
void Person::set_nAge(int t_nAge) { m_nAge = t_nAge; }

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
