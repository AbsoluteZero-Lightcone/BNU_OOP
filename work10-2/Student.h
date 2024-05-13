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

	// Getter & Setter
	string get_strName()const;
	string get_strID()const;
	double get_dChineseScore()const;
	double get_dMathScore()const;
	double get_dEnglishScore()const;
	void set_strName(string t_strName);
	void set_strID(string t_strID);
	void set_dChineseScore(double t_dChineseScore);
	void set_dMathScore(double t_dMathScore);
	void set_dEnglishScore(double t_dEnglishScore);
	
	// ×èÖ¹¸´ÖÆ
	Student(const Student& source) = delete;
	void operator=(const Student& source) = delete;

	friend ostream& operator<<(ostream& out, const Student& source);
	friend istream& operator>>(istream& input, Student& target);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Student& source);
istream& operator>>(istream& input, Student& target);

#endif /* !__STUDENT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
