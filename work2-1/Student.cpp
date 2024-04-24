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
string Student::getName()const { return m_strName; }
string Student::getNumber()const { return m_strNumber; }
char Student::getGender()const { return m_cGender; }
double Student::getScore()const { return m_dScore; }
void Student::setName(string t_strName) { m_strName = t_strName; }
void Student::setNumber(string t_strNumber) { m_strNumber = t_strNumber; }
void Student::setGender(char t_cGender) { m_cGender = t_cGender; }
void Student::setScore(double t_dScore) { m_dScore = t_dScore; }

/* Exported functions ------------------------------------------------------- */

void Student::Show() const{
	cout << *this;
}

Student MaxScore(Student* s,int length) {
	int index;
	double max = 0;
	for (int i = 0; i < length; i++)	{
		if (s[i].m_dScore > max) {
			index = i;
			max = s[i].m_dScore;
		}
	}
	return s[index];
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Student& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Student& source) {
	out << "name:\t" << source.m_strName << endl
		<< "number:\t" << source.m_strNumber << endl
		<< "gender:\t" << source.m_cGender << endl
		<< "score:\t"  << source.m_dScore << endl;
	return out;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
