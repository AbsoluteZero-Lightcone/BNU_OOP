/**
  ******************************************************************************
  * @file    StuEmployee.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   StuEmployee class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "StuEmployee.h"

/* Constructors & Deconstructor --------------------------------------------- */
StuEmployee::StuEmployee() :
	Person(),
	Student(),
	Employee()
{}

StuEmployee::StuEmployee(
	string t_strName, int t_nAge,
	string t_strMajor, string t_strStudentID,
	string t_strDepartment, string t_strEmployeeID
	) :
	Person(t_strName, t_nAge),
	Student(t_strName, t_nAge,t_strMajor, t_strStudentID),
	Employee(t_strName, t_nAge,t_strDepartment, t_strEmployeeID)
{}

StuEmployee::StuEmployee(const StuEmployee& source) :
	Person(source),
	Student(source),
	Employee(source)
{}

StuEmployee::~StuEmployee() {}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
