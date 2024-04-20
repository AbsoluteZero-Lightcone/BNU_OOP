/**
  ******************************************************************************
  * @file    StuEmployee.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   StuEmployee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STUEMPLOYEE_H
#define __STUEMPLOYEE_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "Student.h"
#include "Employee.h"

/* Class ---------------------------------------------------------------------*/
class StuEmployee:public Student,public Employee {
public:
	// Constructors & Deconstructor
	StuEmployee();
	StuEmployee(
		string t_strName, int t_nAge, 
		string t_strMajor, string t_strStudentID,
		string t_strDepartment, string t_strEmployeeID
	);
	StuEmployee(const StuEmployee& source);
	~StuEmployee();
};

#endif /* !__STUEMPLOYEE_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
