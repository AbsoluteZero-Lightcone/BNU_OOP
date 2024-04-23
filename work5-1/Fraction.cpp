/**
  ******************************************************************************
  * @file    Fraction.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Fraction class
  * @encode  GB2312
  ******************************************************************************
  */

#include "Fraction.h"

/* Constructors & Deconstructor --------------------------------------------- */
Fraction::Fraction(const Fraction& n) {
	m_nNum = n.m_nNum;
	m_nDen = n.m_nDen;
}

Fraction::Fraction(int n, int d) {
	if (d == 0) {
		cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
			<< "��ĸ����Ϊ0"
			<< endl;
		abort();
	}
	m_nNum = n;
	m_nDen = d;
	Standardize();
}
Fraction::~Fraction() {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Fraction& source : ������ֵ
  * @retval ��
  */
void Fraction::operator=(const Fraction& source) {
	m_nNum = source.m_nNum;
	m_nDen = source.m_nDen;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Fraction& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Fraction& source) {
	// todo
	return out;
}

/**
  * @brief ���ص��������
  * @param const Fraction& n1 : �������ߵ�ֵ
  * @param const Fraction& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const Fraction& n1, const Fraction& n2) {
	if (n1.m_nNum != n2.m_nNum)return false;
	if (n1.m_nDen != n2.m_nDen)return false;
	return false;
}
/**
  * @brief Լ��
  * @param None
  * @retval None
  */
void Fraction::Standardize() {
	if (m_nNum == 0)m_nDen = 1;
	else {
		int gcd = GCD(m_nNum, m_nDen);
		m_nNum /= gcd;
		m_nDen /= gcd;
	}
}


// �涨����
void Fraction::Show() {
	cout << m_nNum << "/" << m_nDen;
}

Fraction operator+(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen + n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief շת������������������������ɽ��ܸ�����������һ����Ϊ��
  * @param a, b : ��������
  * @retval �������
  */
int GCD(int a, int b) {
	if (a == 0 || b == 0) {
		cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
			<< "������������������ֵ����Ϊ0"
			<< endl;
		abort();
	}
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	if (a > b)swap(a, b);// ��֤  n1 < n2
	int c = a % b;
	while (1) {
		if (b % c == 0)return c;
		// GCD ���� �������飺 
		// ����	a   b    c
		//		a , b , a%b , a%(a%b) , ... , (n-2)%(n-1) , ... , GCD , 0
		// ������ <-- �����ƶ�
		a = b;
		b = c;
		c = a % b;
	}
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
