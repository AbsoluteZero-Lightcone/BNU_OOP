/**
  ******************************************************************************
  * @file    param3operators.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   param3operators class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "param3operators.h"

/* Constructors & Deconstructor --------------------------------------------- */
param3operators::param3operators() :
	m_dataname1(0),
	m_dataname2(0),
	m_dataname3(0)
{}

param3operators::param3operators(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3) :
	m_dataname1(t_dataname1),
	m_dataname2(t_dataname2),
	m_dataname3(t_dataname3)
{}

param3operators::param3operators(const param3operators& source) :
	m_dataname1(source.m_dataname1),
	m_dataname2(source.m_dataname2),
	m_dataname3(source.m_dataname3)
{}

param3operators::~param3operators() {}

/* Getters & Setters -------------------------------------------------------- */
datatype1 param3operators::get_dataname1()const { return m_dataname1; }
void param3operators::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 param3operators::get_dataname2()const { return m_dataname2; }
void param3operators::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }
datatype3 param3operators::get_dataname3()const { return m_dataname3; }
void param3operators::set_dataname3(datatype3 t_dataname3) { m_dataname3 = t_dataname3; }
void param3operators::set(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3) {
	m_dataname1 = t_dataname1; m_dataname2 = t_dataname2; m_dataname3 = t_dataname3;
}

/* Private functions -------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const param3operators& source : ������ֵ
  * @retval ��
  */
void param3operators::operator=(const param3operators& source) {
	m_dataname1 = source.m_dataname1;
	m_dataname2 = source.m_dataname2;
	m_dataname3 = source.m_dataname3;
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void param3operators::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
param3operators& param3operators::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief ��������ǰ���������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
param3operators& param3operators::operator++() {
	// todo
	return *this;
}

/**
  * @brief ��������ǰ�Լ������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
param3operators& param3operators::operator--() {
	// todo
	return *this;
}
/**
  * @brief �������غ����������
  * @param ��
  * @retval ֵ���أ���֧����ʽ����
  */
param3operators param3operators::operator++(int) {
	param3operators temp(*this);
	++(*this);
	return temp;
}

/**
  * @brief �������غ��Լ������
  * @param ��
  * @retval ֵ���أ���֧����ʽ����
  */
param3operators param3operators::operator--(int) {
	param3operators temp(*this);
	--(*this);
	return temp;
}

/**
  * @brief ��������ȡ�������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
param3operators& param3operators::operator!() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const param3operators& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const param3operators& source) {
	// todo
	return out;
}

/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param param3operators& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, param3operators& target){
	cout << "input:";
	input
		>> target.m_dataname1
		>> target.m_dataname2;
	return input;
}

/**
  * @brief ���ش��������
  * @param const param3operators& n1 : �������ߵ�ֵ
  * @param const param3operators& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const param3operators& n1, const param3operators& n2) {
	// todo
	return false;
}

/**
  * @brief ���ش��ڵ��������
  * @param const param3operators& n1 : �������ߵ�ֵ
  * @param const param3operators& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 >= n2
  */
bool operator>=(const param3operators& n1, const param3operators& n2) {
	return (n1 == n2) || (n1 > n2);
}

/**
  * @brief ����С�������
  * @param const param3operators& n1 : �������ߵ�ֵ
  * @param const param3operators& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 < n2
  */
bool operator<(const param3operators& n1, const param3operators& n2) {
	return !(n1 >= n2);
}

/**
  * @brief ����С�ڵ��������
  * @param const param3operators& n1 : �������ߵ�ֵ
  * @param const param3operators& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 <= n2
  */
bool operator<=(const param3operators& n1, const param3operators& n2) {
	return !(n1 > n2);
}

/**
  * @brief ���ص��������
  * @param const param3operators& n1 : �������ߵ�ֵ
  * @param const param3operators& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const param3operators& n1, const param3operators& n2) {
	if (n1.m_dataname1 != n2.m_dataname1)return false;
	if (n1.m_dataname2 != n2.m_dataname2)return false;
	if (n1.m_dataname3 != n2.m_dataname3)return false;
	return true;
}

/**
  * @brief ���ز����������
  * @param const param3operators& n1 : �������ߵ�ֵ
  * @param const param3operators& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 != n2
  */
bool operator!=(const param3operators& n1, const param3operators& n2) {
	if (n1.m_dataname1 == n2.m_dataname1)return false;
	if (n1.m_dataname2 == n2.m_dataname2)return false;
	if (n1.m_dataname3 == n2.m_dataname3)return false;
	return true;
}

/**
  * @brief ���ظ���
  * @param param3operators n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
param3operators operator-(param3operators n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const param3operators& n1 : �Ӻ���ߵ�ֵ
  * @param const param3operators& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
param3operators operator+(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const param3operators& n1 : ������
  * @param const param3operators& n2 : ����
  * @retval n1 - n2
  */
param3operators operator-(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/**
  * @brief ���س˷������
  * @param const param3operators& n1 : �˺���ߵ�ֵ
  * @param const param3operators& n2 : �˺��ұߵ�ֵ
  * @retval n1 * n2
  */
param3operators operator*(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/**
  * @brief ���س��������
  * @param const param3operators& n1 : ������
  * @param const param3operators& n2 : ����
  * @retval n1 / n2
  */
param3operators operator/(const param3operators& n1, const param3operators& n2) {
	param3operators temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
