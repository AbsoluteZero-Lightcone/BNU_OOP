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
	m_chSign('+'),
	m_nYuan(0),
	m_nJiao(0),
	m_nFen(0)
{}

RMB::RMB(int fen) { fromFen(fen); }

RMB::RMB(const RMB& source) :
	m_chSign(source.m_chSign),
	m_nYuan(source.m_nYuan),
	m_nJiao(source.m_nJiao),
	m_nFen(source.m_nFen)
{}

RMB::~RMB() {}

/* Private functions -------------------------------------------------------- */
/**
  * @brief ת��Ϊ��
  * @param None
  * @retval ��
  */
int RMB::toFen()const {
	return (m_chSign == '+' ? 1 : -1) * (m_nYuan * 100 + m_nJiao * 10 + m_nFen);
}
/**
  * @brief �ӷָ�ֵ
  * @param int fen : ��
  * @retval None
  */
void RMB::fromFen(int fen) {
	if (fen >= 0)m_chSign = '+';
	else {
		m_chSign = '-';
		fen = -fen;
	}
	m_nFen = fen % 10;
	fen /= 10;
	m_nJiao = fen % 10;
	m_nYuan = fen / 10;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief �������ظ���
  * @param *this : ֵ���ݴ�ȡ����ֵ
  * @retval -*this
  */
RMB RMB::operator-() {
	return RMB(-(this->toFen()));
}

/**
  * @brief �������ؼӷ������
  * @param *this : �Ӻ���ߵ�ֵ
  * @param const RMB& n2 : �Ӻ��ұߵ�ֵ
  * @retval *this + n2
  */
RMB RMB::operator+(const RMB& n2) {
	return RMB((this->toFen()) + (n2.toFen()));
}

/**
  * @brief �������ؼ��������
  * @param *this : ������
  * @param const RMB& n2 : ����
  * @retval *this - n2
  */
RMB RMB::operator-(const RMB& n2) {
	return RMB((this->toFen()) - (n2.toFen()));
}

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
  * @brief ��������ʹ�÷ָ�ֵ�ĸ�ֵ�����
  * @param int n : ��
  * @retval ��
  */
void RMB::operator=(int n) {
	fromFen(n);
}

/**
  * @brief ��������+=�����
  * @param n : ��
  * @retval ������������ʵ����ʽ���
  */
RMB& RMB::operator+=(int n) {
	fromFen(toFen() + n);
	return *this;
}

/**
  * @brief ��������ǰ���������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
RMB& RMB::operator++() {
	fromFen(toFen() + 1);
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
  * @brief ����ǰ�Լ������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
RMB& operator--(RMB& n) {
	n.fromFen(n.toFen() + 1);
	return n;
}

/**
  * @brief ���غ��Լ������
  * @param ��
  * @retval ֵ���أ���֧����ʽ����
  */
RMB operator--(RMB& n, int) {
	RMB temp(n);
	--n;
	return temp;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const RMB& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const RMB& source) {
	out << "(" << source.m_chSign << source.m_nYuan << "Ԫ" << source.m_nJiao << "��" << source.m_nFen << "��)";
	return out;
}

/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param RMB& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, RMB& target) {
	char         t_chSign;
	unsigned int t_nYuan;
	unsigned int t_nJiao;
	unsigned int t_nFen;

	input
		>> t_chSign
		>> t_nYuan
		>> t_nJiao
		>> t_nFen;
	if (t_chSign != '+' && t_chSign != '-') {
		cerr << "Incorrect sign. Please try again:";
		input >> target;
	}
	else {
		target.m_chSign = t_chSign;
		target.m_nYuan = t_nYuan;
		target.m_nJiao = t_nJiao;
		target.m_nFen = t_nFen;
	}
	return input;
}

/**
  * @brief ���ش��������
  * @param const RMB& n1 : �������ߵ�ֵ
  * @param const RMB& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const RMB& n1, const RMB& n2) {
	return n1.toFen() > n2.toFen();
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

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
