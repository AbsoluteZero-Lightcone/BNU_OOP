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
	Student();
	Student(
		string t_strName,
		string t_strNumber,
		char t_cGender,
		double t_dScore
	);
	~Student();

	// Getter & Setter
	string get_strName()const;
	string get_strNumber()const;
	char get_cGender()const;
	double get_dScore()const;
	void set_strName(string t_strName);
	void set_strNumber(string t_strNumber);
	void set_cGender(char t_cGender);
	void set_dScore(double t_dScore);
	
	// ×èÖ¹¸´ÖÆ
	Student(const Student& source) = delete;
	void operator=(const Student& source) = delete;

	friend ostream& operator<<(ostream& out, const Student& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Student& source);

#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
