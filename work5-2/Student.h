/**
  ******************************************************************************
  * @file    Student.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
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

/* Class ---------------------------------------------------------------------*/
class Student {
private:
	string m_strName;
	int m_nCredit;
	int m_nScore;
public:
	// Constructors & Deconstructor
	Student();
	Student(string t_strName, int t_nCredit, int t_nScore);
	Student(const Student& source);
	~Student();

	// Getter & Setter
	string get_strName()const;
	void set_strName(string t_strName);
	int get_nCredit()const;
	void set_nCredit(int t_nCredit);
	int get_nScore()const;
	void set_nScore(int t_nCredit);

	friend class Teacher;
};

#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
