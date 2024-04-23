/**
  ******************************************************************************
  * @file    Fraction.cpp
  * @author  ���෨ 202311998186
  * @date    2024-04-20
  * @brief   ��������
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
	Format();
}
Fraction::~Fraction() {}

/* Private functions -------------------------------------------------------- */
/**
  * @brief Լ��
  * @param None
  * @retval None
  */
void Fraction::Format() {
	if (m_nNum == 0)m_nDen = 1;
	else {
		int gcd = GCD(m_nNum, m_nDen);
		m_nNum /= gcd;
		m_nDen /= gcd;
	}
}

/* Exported functions ------------------------------------------------------- */
// �涨����
void Fraction::Show() {
	cout << *this;
}

void Fraction::Add(Sum* num) {
	Fraction* n = dynamic_cast<Fraction*>(num);
	if (n != NULL) {
		Fraction(*n + *this).Show();
	}
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Fraction& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Fraction& source) {
	if (source.m_nDen == 1) {
		out << source.m_nNum;
		return out;
	}
	else {
		out << source.m_nNum << "/" << source.m_nDen;
		return out;
	}
}

Fraction operator+(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen + n1.m_nDen * n2.m_nNum;
	f.Format();
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
