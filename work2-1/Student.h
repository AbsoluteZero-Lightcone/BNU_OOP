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

	double GetScore() const;
	void Show() const;

	// Getter & Setter
	string get_strName()const;
	string get_strNumber()const;
	char get_cGender()const;
	double get_dScore()const;
	void set_strName(string t_strName);
	void set_strNumber(string t_strNumber);
	void set_cGender(char t_cGender);
	void set_dScore(double t_dScore);
	
	friend ostream& operator<<(ostream& out, const Student& source);
	friend Student MaxScore(Student* s);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Student& source);
Student MaxScore(Student* s);
#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
