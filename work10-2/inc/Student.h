/**
  ******************************************************************************
  * @file    Student.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-13
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
	string m_strID;
	double m_dChineseScore;
	double m_dMathScore;
	double m_dEnglishScore;
public:
	// Constructors & Deconstructor
	Student();
	Student(
		string t_strName,
		string t_strID,
		double t_dChineseScore,
		double t_dMathScore,
		double t_dEnglishScore
	);
	~Student();
	
	static void sort(Student** arr,int length);

	// Getter & Setter
	double getSum()const;

	friend ostream& operator<<(ostream& out, const Student& source);
	friend istream& operator>>(istream& input, Student& target);

	friend bool operator==(const Student& a, const Student& b);
	friend bool operator!=(const Student& a, const Student& b);
	friend bool operator>=(const Student& a, const Student& b);
	friend bool operator<=(const Student& a, const Student& b);
	friend bool operator>(const Student& a, const Student& b);
	friend bool operator<(const Student& a, const Student& b);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Student& source);
istream& operator>>(istream& input, Student& target);
bool operator==(const Student& a, const Student& b);
bool operator!=(const Student& a, const Student& b);
bool operator>=(const Student& a, const Student& b);
bool operator<=(const Student& a, const Student& b);
bool operator>(const Student& a, const Student& b);
bool operator<(const Student& a, const Student& b);
#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
