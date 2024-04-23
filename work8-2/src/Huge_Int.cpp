/**
  ******************************************************************************
  * @file    Huge_Int.cpp
  * @author  ���෨ 202311998186
  * @date    2024-04-19
  * @brief   �߾�����������
  ******************************************************************************
  */
#include "Huge_Int.h"

int getStringLength(const char* str);
Huge_Int::Huge_Int(const char* str) {
	bool isSigned = 0;
	if (str[0] == '+' || str[0] == '-') {
		m_cSign = str[0];
		isSigned = 1;
	}
	else if (str[0] >= '0' && str[0] <= '9') {
		m_cSign = '+';
		isSigned = 0;
	}
	else {
		throw "��Ч��������";
	}
	int numLength = getStringLength(str) - isSigned;
	for (int i = 0; i < numLength; i++) {
		int index_of_str = i + isSigned;
		if (str[index_of_str] >= '0' && str[index_of_str] <= '9')
			m_nUnsignedData[(numLength - 1) - i] = str[index_of_str] - '0';
		else {
			throw "��Ч����ֵ";// main�����Ӽ�������Ļ�Ҫ�����쳣
		}
	}
}
Huge_Int::~Huge_Int() {}

void Huge_Int::operator=(const Huge_Int& n) {
	m_cSign = n.m_cSign;
	for (int i = 0; i < 110; i++) {
		m_nUnsignedData[i] = n.m_nUnsignedData[i];
	}
}

int getStringLength(const char* str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
ostream& operator<<(ostream& out, const Huge_Int& n) {
	if (n.m_cSign == '-')out << '-';
	bool started = 0;// �ж��Ƿ���Ч������
	for (int i = 110 - 1; i >= 0; i--) {
		if (!started)
			if (n.m_nUnsignedData[i] == 0)
				continue;
			else started = 1;
		out << n.m_nUnsignedData[i];
	}
	return out;
}
bool operator>(const Huge_Int& n1, const Huge_Int& n2) {
	if (n1.m_cSign == '+' && n2.m_cSign == '-')return 1;
	else if (n1.m_cSign == '-' && n2.m_cSign == '+')return 0;
	else if (n1.m_cSign == '+' && n2.m_cSign == '+') {
		for (int i = 110 - 1; i >= 0; i--) {
			if (n1.m_nUnsignedData[i] > n2.m_nUnsignedData[i])
				return 1;// ����
			if (n1.m_nUnsignedData[i] < n2.m_nUnsignedData[i])
				return 0;// С�ڣ���֦��
		}
		return 0;// ����
	}
	else if (n1.m_cSign == '-' && n2.m_cSign == '-')
	{
		for (int i = 110 - 1; i >= 0; i--) {
			if (n1.m_nUnsignedData[i] > n2.m_nUnsignedData[i])
				return 0;
			if (n1.m_nUnsignedData[i] < n2.m_nUnsignedData[i])
				return 1;
		}
		return 1;
	}
	else {
		cerr << "Error: in file \"" << __FILE__ << "\",Line " << __LINE__ << ": "
			<< "�Ƿ���������"
			<< endl;
		abort();
	}
}
Huge_Int operator-(Huge_Int n) {
	if (n.m_cSign == '+')n.m_cSign = '-';
	if (n.m_cSign == '-')n.m_cSign = '+';
	return n;
}
Huge_Int abs(Huge_Int n) {
	if (n.m_cSign == '-')n.m_cSign = '+';
	return n;
}
Huge_Int operator+(const Huge_Int& n1, const Huge_Int& n2) {
	Huge_Int sum("0");
	if (n1.m_cSign == n2.m_cSign) {
		// ͬ������
		sum.m_cSign = n1.m_cSign;
		bool carryFlag = 0;// ��λ
		for (int i = 0; i < 110; i++) {// �ɵ�λ����λ
			sum.m_nUnsignedData[i] = n1.m_nUnsignedData[i] + n2.m_nUnsignedData[i] + carryFlag;
			if (sum.m_nUnsignedData[i] >= 10) {
				carryFlag = 1;
				sum.m_nUnsignedData[i] -= 10;
			}
			else carryFlag = 0;
		}
	}
	else {
		// �������
		if (abs(n1) > abs(n2)) {
			sum.m_cSign = n1.m_cSign;
			bool carryFlag = 0;// ��λ
			for (int i = 0; i < 110; i++) {// �ɵ�λ����λ
				sum.m_nUnsignedData[i] = n1.m_nUnsignedData[i] - n2.m_nUnsignedData[i] - carryFlag;
				if (sum.m_nUnsignedData[i] < 0) {
					carryFlag = 1;
					sum.m_nUnsignedData[i] += 10;
				}
			}
		}
		else {
			sum.m_cSign = n2.m_cSign;
			bool carryFlag = 0;// ��λ
			for (int i = 0; i < 110; i++) {// �ɵ�λ����λ
				sum.m_nUnsignedData[i] = n2.m_nUnsignedData[i] - n1.m_nUnsignedData[i] - carryFlag;
				if (sum.m_nUnsignedData[i] < 0) {
					carryFlag = 1;
					sum.m_nUnsignedData[i] += 10;
				}
			}
		}
	}
	return sum;
}
Huge_Int operator-(const Huge_Int& n1, const Huge_Int& n2) {
	return n1 + (-n2);
}


// �涨����
void Huge_Int::Show() {
	cout << *this;
}

void Huge_Int::Add(Sum* num) {
	cout << *this + *dynamic_cast<Huge_Int*>(num);
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
