/**
  ******************************************************************************
  * @file    Student.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.2.0
  * @date    2024-04-23
  * @brief   Student class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Student.h"

/* Constructors & Deconstructor --------------------------------------------- */
Student::Student() :
	m_strName(""),
	m_nCredit(0),
	m_nScore(0)
{}

Student::Student(string t_strName, int t_nCredit, int t_nScore) :
	m_strName(t_strName),
	m_nCredit(t_nCredit),
	m_nScore(t_nScore)
{}

Student::Student(const Student& source) :
	m_strName(source.m_strName),
	m_nCredit(source.m_nCredit),
	m_nScore(source.m_nScore)
{}

Student::~Student() {}

/* Getters & Setters -------------------------------------------------------- */
string Student::get_strName()const { return m_strName; }
void Student::set_strName(string t_strName) { m_strName = t_strName; }
int Student::get_nCredit()const { return m_nCredit; }
void Student::set_nCredit(int t_nCredit) { m_nCredit = t_nCredit; }
int Student::get_nScore()const { return m_nScore; }
void Student::set_nScore(int t_nScore) { m_nScore = t_nScore; }


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
