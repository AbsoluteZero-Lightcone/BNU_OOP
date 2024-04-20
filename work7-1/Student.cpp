/**
  ******************************************************************************
  * @file    Student.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Student class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Student.h"

/* Constructors & Deconstructor --------------------------------------------- */
Student::Student(){}
Student::Student(const Student& source) {}
Student::~Student() {}

/* Getters & Setters -------------------------------------------------------- */
string Student::get_strMajor() { return m_strMajor; }
void Student::set_strMajor(string t_strMajor) { m_strMajor = t_strMajor; }
string Student::get_strStudentID() { return m_strStudentID; }
void Student::set_strStudentID(string t_strStudentID) { m_strStudentID = t_strStudentID; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Student& source : ������ֵ
  * @retval ��
  */
void Student::operator=(const Student& source) {
	// todo
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void Student::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
Student& Student::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief �����������������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
Student& Student::operator++() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Student& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Student& source) {
	// todo
	return out;
}

/**
  * @brief ���ش��������
  * @param const Student& n1 : �������ߵ�ֵ
  * @param const Student& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const Student& n1, const Student& n2) {
	// todo
	return false;
}

/**
  * @brief ���ص��������
  * @param const Student& n1 : �������ߵ�ֵ
  * @param const Student& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Student& n1, const Student& n2) {
	// todo
	return false;
}

/**
  * @brief ���ظ���
  * @param Student n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
Student operator-(Student n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const Student& n1 : �Ӻ���ߵ�ֵ
  * @param const Student& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
Student operator+(const Student& n1, const Student& n2) {
	Student temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const Student& n1 : ������
  * @param const Student& n2 : ����
  * @retval n1 - n2
  */
Student operator-(const Student& n1, const Student& n2) {
	Student temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
