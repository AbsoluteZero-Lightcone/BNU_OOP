/**
  ******************************************************************************
  * @file    Employee.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Employee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Employee.h"

/* Constructors & Deconstructor --------------------------------------------- */
Employee::Employee() :
	m_strDepartment(0),
	m_strEmployeeID(0)
{}

Employee::Employee(string t_strDepartment, string t_strEmployeeID):
	m_strDepartment(t_strDepartment), 
	m_strEmployeeID(t_strEmployeeID)
{}

Employee::Employee(const Employee& source) :
	m_strDepartment(source.m_strDepartment),
	m_strEmployeeID(source.m_strEmployeeID)
{}

Employee::~Employee() {}

/* Getters & Setters -------------------------------------------------------- */
string Employee::get_strDepartment() { return m_strDepartment; }
void Employee::set_strDepartment(string t_strDepartment) { m_strDepartment = t_strDepartment; }
string Employee::get_strEmployeeID() { return m_strEmployeeID; }
void Employee::set_strEmployeeID(string t_strEmployeeID) { m_strEmployeeID = t_strEmployeeID; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Employee& source : ������ֵ
  * @retval ��
  */
void Employee::operator=(const Employee& source) {
	// todo
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void Employee::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
Employee& Employee::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief �����������������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
Employee& Employee::operator++() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Employee& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Employee& source) {
	// todo
	return out;
}

/**
  * @brief ���ش��������
  * @param const Employee& n1 : �������ߵ�ֵ
  * @param const Employee& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const Employee& n1, const Employee& n2) {
	// todo
	return false;
}

/**
  * @brief ���ص��������
  * @param const Employee& n1 : �������ߵ�ֵ
  * @param const Employee& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Employee& n1, const Employee& n2) {
	// todo
	return false;
}

/**
  * @brief ���ظ���
  * @param Employee n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
Employee operator-(Employee n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const Employee& n1 : �Ӻ���ߵ�ֵ
  * @param const Employee& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
Employee operator+(const Employee& n1, const Employee& n2) {
	Employee temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const Employee& n1 : ������
  * @param const Employee& n2 : ����
  * @retval n1 - n2
  */
Employee operator-(const Employee& n1, const Employee& n2) {
	Employee temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
