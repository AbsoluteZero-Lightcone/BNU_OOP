/**
  ******************************************************************************
  * @file    Student.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Student class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Student.h"

/* Constructors & Deconstructor --------------------------------------------- */
Student::Student(
	string t_strName,
	string t_strNumber,
	char t_cGender,
	double t_dScore
) :
	m_strName(t_strName),
	m_strNumber(t_strNumber),
	m_cGender(t_cGender),
	m_dScore(t_dScore)
{}

Student::~Student() {}

/* Getters & Setters -------------------------------------------------------- */
string Student::get_strName()const { return m_strName; }
string Student::get_strNumber()const { return m_strNumber; }
char Student::get_cGender()const { return m_cGender; }
double Student::get_dScore()const { return m_dScore; }
void Student::set_strName(string t_strName) { m_strName = t_strName; }
void Student::set_strNumber(string t_strNumber) { m_strNumber = t_strNumber; }
void Student::set_cGender(char t_cGender) { m_cGender = t_cGender; }
void Student::set_dScore(double t_dScore) { m_dScore = t_dScore; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Student& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Student& source) {
	// todo
	return out;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
