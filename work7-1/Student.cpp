/**
  ******************************************************************************
  * @file    Student.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Student class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Student.h"

/* Constructors & Deconstructor --------------------------------------------- */
Student::Student() :
	Person(),
	m_strMajor("ȱʡ"),
	m_strStudentID("ȱʡ")
{}
Student::Student(string t_strName, int t_nAge, string t_strMajor,string t_strStudentID) :
	Person(t_strName, t_nAge),
	m_strMajor(t_strMajor),
	m_strStudentID(t_strStudentID)
{}
Student::Student(const Student& source) :
	Person(source),
	m_strMajor(source.m_strMajor),
	m_strStudentID(source.m_strStudentID)
{}
Student::~Student() {}

/* Getters & Setters -------------------------------------------------------- */
string Student::get_strMajor() { return m_strMajor; }
void Student::set_strMajor(string t_strMajor) { m_strMajor = t_strMajor; }
string Student::get_strStudentID() { return m_strStudentID; }
void Student::set_strStudentID(string t_strStudentID) { m_strStudentID = t_strStudentID; }

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
