/**
  ******************************************************************************
  * @file    Student.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Student class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STUDENT_H
#define __STUDENT_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "Person.h"

/* Class ---------------------------------------------------------------------*/
class Student :virtual public Person {
private:
	string m_strMajor;
	string m_strStudentID;
public:
	// Constructors & Deconstructor
	Student();
	Student(string t_strName, int t_nAge, string t_strMajor, string t_strStudentID);
	Student(const Student& source);
	~Student();

	// Getter & Setter
	string get_strMajor();
	void set_strMajor(string t_strMajor);
	string get_strStudentID();
	void set_strStudentID(string t_strStudentID);

};

#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
