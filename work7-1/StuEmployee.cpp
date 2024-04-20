/**
  ******************************************************************************
  * @file    StuEmployee.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   StuEmployee class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "StuEmployee.h"

/* Constructors & Deconstructor --------------------------------------------- */
StuEmployee::StuEmployee() 
{}

StuEmployee::StuEmployee(const StuEmployee& source) 
{}

StuEmployee::~StuEmployee() {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const StuEmployee& source : ������ֵ
  * @retval ��
  */
void StuEmployee::operator=(const StuEmployee& source) {
	// todo
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void StuEmployee::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
StuEmployee& StuEmployee::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief �����������������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
StuEmployee& StuEmployee::operator++() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const StuEmployee& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const StuEmployee& source) {
	// todo
	return out;
}

/**
  * @brief ���ش��������
  * @param const StuEmployee& n1 : �������ߵ�ֵ
  * @param const StuEmployee& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const StuEmployee& n1, const StuEmployee& n2) {
	// todo
	return false;
}

/**
  * @brief ���ص��������
  * @param const StuEmployee& n1 : �������ߵ�ֵ
  * @param const StuEmployee& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const StuEmployee& n1, const StuEmployee& n2) {
	// todo
	return false;
}

/**
  * @brief ���ظ���
  * @param StuEmployee n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
StuEmployee operator-(StuEmployee n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const StuEmployee& n1 : �Ӻ���ߵ�ֵ
  * @param const StuEmployee& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
StuEmployee operator+(const StuEmployee& n1, const StuEmployee& n2) {
	StuEmployee temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const StuEmployee& n1 : ������
  * @param const StuEmployee& n2 : ����
  * @retval n1 - n2
  */
StuEmployee operator-(const StuEmployee& n1, const StuEmployee& n2) {
	StuEmployee temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
