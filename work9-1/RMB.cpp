/**
  ******************************************************************************
  * @file    RMB.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   RMB class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "RMB.h"

/* Constructors & Deconstructor --------------------------------------------- */
RMB::RMB() :
	m_nYuan(0),
	m_nJiao(0),
	m_nFen(0)
{}

RMB::RMB(const RMB& source) :
	m_chSign(source.m_chSign),
	m_nYuan(source.m_nYuan),
	m_nJiao(source.m_nJiao),
	m_nFen(source.m_nFen)
{}

RMB::~RMB() {}

/* Private functions -------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const RMB& source : ������ֵ
  * @retval ��
  */
void RMB::operator=(const RMB& source) {
	m_chSign = source.m_chSign;
	m_nYuan = source.m_nYuan;
	m_nJiao = source.m_nJiao;
	m_nFen = source.m_nFen;
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void RMB::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
RMB& RMB::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief ��������ǰ���������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
RMB& RMB::operator++() {
	// todo
	return *this;
}

/**
  * @brief ��������ǰ�Լ������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
RMB& RMB::operator--() {
	// todo
	return *this;
}
/**
  * @brief �������غ����������
  * @param ��
  * @retval ֵ���أ���֧����ʽ����
  */
RMB RMB::operator++(int) {
	RMB temp(*this);
	++(*this);
	return temp;
}

/**
  * @brief �������غ��Լ������
  * @param ��
  * @retval ֵ���أ���֧����ʽ����
  */
RMB RMB::operator--(int) {
	RMB temp(*this);
	--(*this);
	return temp;
}

/**
  * @brief ��������ȡ�������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
RMB& RMB::operator!() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const RMB& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const RMB& source) {
	// todo
	return out;
}

/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param RMB& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, RMB& target){
	cout << "input:";
	input
		>> target.m_nYuan
		>> target.m_nJiao;
	return input;
}

/**
  * @brief ���ش��������
  * @param const RMB& n1 : �������ߵ�ֵ
  * @param const RMB& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const RMB& n1, const RMB& n2) {
	// todo
	return false;
}

/**
  * @brief ���ش��ڵ��������
  * @param const RMB& n1 : �������ߵ�ֵ
  * @param const RMB& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 >= n2
  */
bool operator>=(const RMB& n1, const RMB& n2) {
	return (n1 == n2) || (n1 > n2);
}

/**
  * @brief ����С�������
  * @param const RMB& n1 : �������ߵ�ֵ
  * @param const RMB& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 < n2
  */
bool operator<(const RMB& n1, const RMB& n2) {
	return !(n1 >= n2);
}

/**
  * @brief ����С�ڵ��������
  * @param const RMB& n1 : �������ߵ�ֵ
  * @param const RMB& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 <= n2
  */
bool operator<=(const RMB& n1, const RMB& n2) {
	return !(n1 > n2);
}

/**
  * @brief ���ص��������
  * @param const RMB& n1 : �������ߵ�ֵ
  * @param const RMB& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const RMB& n1, const RMB& n2) {
	if (n1.m_chSign != n2.m_chSign)return false;
	if (n1.m_nYuan != n2.m_nYuan)return false;
	if (n1.m_nJiao != n2.m_nJiao)return false;
	if (n1.m_nFen != n2.m_nFen)return false;
	return true;
}

/**
  * @brief ���ز����������
  * @param const RMB& n1 : �������ߵ�ֵ
  * @param const RMB& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 != n2
  */
bool operator!=(const RMB& n1, const RMB& n2) {
	if (n1.m_chSign == n2.m_chSign)return false;
	if (n1.m_nYuan == n2.m_nYuan)return false;
	if (n1.m_nJiao == n2.m_nJiao)return false;
	if (n1.m_nFen == n2.m_nFen)return false;
	return true;
}

/**
  * @brief ���ظ���
  * @param RMB n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
RMB operator-(RMB n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const RMB& n1 : �Ӻ���ߵ�ֵ
  * @param const RMB& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
RMB operator+(const RMB& n1, const RMB& n2) {
	RMB temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const RMB& n1 : ������
  * @param const RMB& n2 : ����
  * @retval n1 - n2
  */
RMB operator-(const RMB& n1, const RMB& n2) {
	RMB temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
