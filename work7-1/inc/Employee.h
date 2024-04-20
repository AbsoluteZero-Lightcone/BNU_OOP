/**
  ******************************************************************************
  * @file    Employee.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Employee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "Person.h"

/* Class ---------------------------------------------------------------------*/
class Employee:virtual public Person {
private:
	string m_strDepartment;
	string m_strEmployeeID;
public:
	// Constructors & Deconstructor
	Employee();
	Employee(string t_strName, int t_nAge,string t_strDepartment, string t_strEmployeeID);
	Employee(const Employee& source);
	~Employee();

	// Getter & Setter
	string get_strDepartment();
	void set_strDepartment(string t_strDepartment);
	string get_strEmployeeID();
	void set_strEmployeeID(string t_strEmployeeID);

};

#endif /* !__EMPLOYEE_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
