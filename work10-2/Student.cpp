/**
  ******************************************************************************
  * @file    Student.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-13
  * @brief   Student class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Student.h"

/* Constructors & Deconstructor --------------------------------------------- */
Student::Student() :
	m_strName("XXX"),
	m_strID("000"),
	m_dChineseScore(0),
	m_dMathScore(0),
	m_dEnglishScore(0)
{}

Student::Student(
	string t_strName,
	string t_strID,
	double t_dChineseScore,
	double t_dMathScore,
	double t_dEnglishScore
) :
	m_strName(t_strName),
	m_strID(t_strID),
	m_dChineseScore(t_dChineseScore),
	m_dMathScore(t_dMathScore),
	m_dEnglishScore(t_dEnglishScore)
{}

Student::~Student() {}

void Student::sort(Student** arr, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++) {
			if (arr[i]->getSum() < arr[j]->getSum()) {
				Student* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

/* Getters & Setters -------------------------------------------------------- */
string Student::get_strName()const { return m_strName; }
string Student::get_strID()const { return m_strID; }
double Student::get_dChineseScore()const { return m_dChineseScore; }
double Student::get_dMathScore()const { return m_dMathScore; }
double Student::get_dEnglishScore()const { return m_dEnglishScore; }
void Student::set_strName(string t_strName) { m_strName = t_strName; }
void Student::set_strID(string t_strID) { m_strID = t_strID; }
void Student::set_dChineseScore(double t_dChineseScore) { m_dChineseScore = t_dChineseScore; }
void Student::set_dMathScore(double t_dMathScore) { m_dMathScore = t_dMathScore; }
void Student::set_dEnglishScore(double t_dEnglishScore) { m_dEnglishScore = t_dEnglishScore; }

double Student::getSum() const {
	return m_dChineseScore + m_dMathScore + m_dEnglishScore;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Student& source : ������Ķ���
  * @retval ostream& ʵ����ʽ���
  */
ostream& operator<<(ostream& out, const Student& source) {
	out << source.m_strName << "\t"
		<< source.m_strID << "\t"
		<< source.m_dChineseScore << "\t"
		<< source.m_dMathScore << "\t"
		<< source.m_dEnglishScore << "\t"
		<< source.getSum();
	return out;
}

/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param Student& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, Student& target)
{
	cout << "input:";
	input
		>> target.m_strName
		>> target.m_strID
		>> target.m_dChineseScore
		>> target.m_dMathScore
		>> target.m_dEnglishScore;
	return input;
}

bool operator==(const Student& a, const Student& b) { return a.getSum() == b.getSum(); }
bool operator!=(const Student& a, const Student& b) { return a.getSum() != b.getSum(); }
bool operator>=(const Student& a, const Student& b) { return a.getSum() >= b.getSum(); };
bool operator<=(const Student& a, const Student& b) { return a.getSum() <= b.getSum(); };
bool operator>(const Student& a, const Student& b) { return a.getSum() > b.getSum(); };
bool operator<(const Student& a, const Student& b) { return a.getSum() < b.getSum(); };
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
