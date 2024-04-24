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
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Student {
private:
	string m_strName;
	string m_strNumber;
	char m_cGender;
	double m_dScore;
public:
	// Constructors & Deconstructor
	Student(
		string t_strName = "xxx",
		string t_strNumber = "200010000001",
		char t_cGender = 'm',
		double t_dScore = 0
	);
	~Student();

	void Show() const;

	// Getter & Setter
	string getName()const;
	string getNumber()const;
	char getGender()const;
	double getScore()const;
	void setName(string t_strName);
	void setNumber(string t_strNumber);
	void setGender(char t_cGender);
	void setScore(double t_dScore);
	
	friend ostream& operator<<(ostream& out, const Student& source);
	friend Student MaxScore(Student* s, int length);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Student& source);
Student MaxScore(Student* s, int length);
#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
