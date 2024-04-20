/**
  ******************************************************************************
  * @file    Person.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Person class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Person.h"

/* Constructors & Deconstructor --------------------------------------------- */
Person::Person() :
	m_strName(0),
	m_nAge(0)
{}

Person::Person(string t_strName, int t_nAge):
	m_strName(t_strName), 
	m_nAge(t_nAge)
{}

Person::Person(const Person& source) :
	m_strName(source.m_strName),
	m_nAge(source.m_nAge)
{}

Person::~Person() {}

/* Getters & Setters -------------------------------------------------------- */
string Person::get_strName() { return m_strName; }
void Person::set_strName(string t_strName) { m_strName = t_strName; }
int Person::get_nAge() { return m_nAge; }
void Person::set_nAge(int t_nAge) { m_nAge = t_nAge; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Person& source : ������ֵ
  * @retval ��
  */
void Person::operator=(const Person& source) {
	// todo
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void Person::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
Person& Person::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief �����������������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
Person& Person::operator++() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Person& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Person& source) {
	// todo
	return out;
}

/**
  * @brief ���ش��������
  * @param const Person& n1 : �������ߵ�ֵ
  * @param const Person& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const Person& n1, const Person& n2) {
	// todo
	return false;
}

/**
  * @brief ���ص��������
  * @param const Person& n1 : �������ߵ�ֵ
  * @param const Person& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Person& n1, const Person& n2) {
	// todo
	return false;
}

/**
  * @brief ���ظ���
  * @param Person n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
Person operator-(Person n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const Person& n1 : �Ӻ���ߵ�ֵ
  * @param const Person& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
Person operator+(const Person& n1, const Person& n2) {
	Person temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const Person& n1 : ������
  * @param const Person& n2 : ����
  * @retval n1 - n2
  */
Person operator-(const Person& n1, const Person& n2) {
	Person temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
