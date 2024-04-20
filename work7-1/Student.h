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
	Student(const Student& source);
	~Student();

	// Getter & Setter
	string get_strMajor();
	void set_strMajor(string t_strMajor);
	string get_strStudentID();
	void set_strStudentID(string t_strStudentID);

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Student& source);
	void operator=(int n);
	Student& operator+=(int n);
	Student& operator++();
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Student& source);
bool operator>(const Student& n1, const Student& n2);
bool operator==(const Student& n1, const Student& n2);
Student operator-(Student n);
Student operator+(const Student& n1, const Student& n2);
Student operator-(const Student& n1, const Student& n2);

#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
