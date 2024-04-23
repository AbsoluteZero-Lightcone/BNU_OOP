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
Fraction::Fraction(int n, int d) {
	Set(n,d);
}

Fraction::Fraction(const Fraction& n) {
	m_nNum = n.m_nNum;
	m_nDen = n.m_nDen;
}

Fraction::~Fraction() {}

/* Private functions -------------------------------------------------------- */
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
/* Exported functions ------------------------------------------------------- */

// �涨����
void Fraction::Show()const {
	cout << *this;
}

void Fraction::Set(int n, int d) {
	if (d == 0) {
		//cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
		//	<< "��ĸ����Ϊ0"
		//	<< endl;
		//abort();
		throw "Den can��t be 0.";
	}
	m_nNum = n;
	m_nDen = d;
	Standardize();
}

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
	out << source.m_nNum << "/" << source.m_nDen;
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
  * @brief ���ؼӷ������
  * @param const Fraction& n1 : �Ӻ���ߵ�ֵ
  * @param const Fraction& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
Fraction operator+(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen + n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief ���ظ���
  * @param Fraction n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
Fraction operator-(Fraction n) {
	n.m_nNum = -n.m_nNum;
	return n;
}

/**
  * @brief ���ؼ��������
  * @param const Fraction& n1 : ������ߵ�ֵ
  * @param const Fraction& n2 : �����ұߵ�ֵ
  * @retval n1 - n2
  */
Fraction operator-(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen - n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief ���س˷������
  * @param const Fraction& n1 : �˺���ߵ�ֵ
  * @param const Fraction& n2 : �˺��ұߵ�ֵ
  * @retval n1 * n2
  */
Fraction operator*(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nNum = n1.m_nNum * n2.m_nNum;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.Standardize();
	return f;
}

/**
  * @brief ���س��������
  * @param const Fraction& n1 : ������ߵ�ֵ
  * @param const Fraction& n2 : �����ұߵ�ֵ������Ϊ0
  * @retval n1 / n2
  */
Fraction operator/(const Fraction& n1, const Fraction& n2) {
	if (n2.m_nNum == 0) {
		//cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
		//	<< "��������Ϊ0"
		//	<< endl;
		//abort();
		throw "Can��t divide by 0 .";
	}
	Fraction f;
	f.m_nNum = n1.m_nNum * n2.m_nDen;
	f.m_nDen = n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief շת������������������������ɽ��ܸ�����������һ����Ϊ��
  * @param n1, n2 : ��������
  * @retval �������
  */
int GCD(int n1, int n2) {
	if (n1 == 0 || n2 == 0) {
		cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
			<< "������������������ֵ����Ϊ0"
			<< endl;
		abort();
	}
	if (n1 < 0)n1 = -n1;
	if (n2 < 0)n2 = -n2;
	if (n1 > n2)swap(n1, n2);// ��֤  n1 < n2
	int n0;
	while (1) {
		if (n1 % n2 == 0)return n2;
		// GCD ���� �������飺 
		// ����	n0	n1   n2   
		//		    a1 , a2 , a3 = a1%a2 , a4 = a2%(a1%a2) , ... , an = a(n-2)%a(n-1) , ... , GCD , 0
		// ������ <-- �����ƶ�
		n0 = n1;
		n1 = n2;
		n2 = n0 % n1;
	}
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
