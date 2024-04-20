/**
  ******************************************************************************
  * @file    Employee.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Employee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Employee.h"

/* Constructors & Deconstructor --------------------------------------------- */
Employee::Employee() :
	Person(),
	m_strDepartment("ȱʡ"),
	m_strEmployeeID("ȱʡ")
{}

Employee::Employee(string t_strName, int t_nAge, string t_strDepartment, string t_strEmployeeID):
	Person(t_strName, t_nAge),
	m_strDepartment(t_strDepartment), 
	m_strEmployeeID(t_strEmployeeID)
{}

Employee::Employee(const Employee& source) :
	Person(source),
	m_strDepartment(source.m_strDepartment),
	m_strEmployeeID(source.m_strEmployeeID)
{}

Employee::~Employee() {}

/* Getters & Setters -------------------------------------------------------- */
string Employee::get_strDepartment() { return m_strDepartment; }
void Employee::set_strDepartment(string t_strDepartment) { m_strDepartment = t_strDepartment; }
string Employee::get_strEmployeeID() { return m_strEmployeeID; }
void Employee::set_strEmployeeID(string t_strEmployeeID) { m_strEmployeeID = t_strEmployeeID; }

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
