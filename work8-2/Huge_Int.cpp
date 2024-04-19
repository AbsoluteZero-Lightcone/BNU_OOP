/**
  ******************************************************************************
  * @file    Huge_Int.cpp
  * @author  张亦法
  * @date    2024-04-19
  * @brief   高精度整数类型
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
	else {
		m_cSign = '+';
		isSigned = 0;
	}
	int unsignedLength = getStringLength(str) - isSigned;
	for (int i = 0; i < unsignedLength; i++) {
		m_nUnsignedData[unsignedLength - i - 1] = str[i + isSigned] - '0';
	}
}
Huge_Int::~Huge_Int() {}
void Huge_Int::Show() {
	cout << *this;
}

void Huge_Int::Add(Sum* num) {
	cout << *(Huge_Int*)this + *(Huge_Int*)num;
}
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
	bool started = 0;// 判断是否到有效数字区
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
	if (n1.m_cSign == '-' && n2.m_cSign == '+')return 0;
	if (n1.m_cSign == '+' && n2.m_cSign == '+') {
		for (int i = 110 - 1; i >= 0; i--) {
			if (n1.m_nUnsignedData[i] > n2.m_nUnsignedData[i])
				return 1;// 大于
			if (n1.m_nUnsignedData[i] < n2.m_nUnsignedData[i])
				return 0;// 小于（剪枝）
		}
		return 0;// 等于
	}
	if (n1.m_cSign == '-' && n2.m_cSign == '-') {
		for (int i = 110 - 1; i >= 0; i--) {
			if (n1.m_nUnsignedData[i] > n2.m_nUnsignedData[i])
				return 0;
			if (n1.m_nUnsignedData[i] < n2.m_nUnsignedData[i])
				return 1;
		}
		return 1;
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
		// 同号情形
		sum.m_cSign = n1.m_cSign;
		bool carryFlag = 0;// 进位
		for (int i = 0; i < 110; i++) {// 由低位到高位
			sum.m_nUnsignedData[i] = n1.m_nUnsignedData[i] + n2.m_nUnsignedData[i] + carryFlag;
			if (sum.m_nUnsignedData[i] >= 10) {
				carryFlag = 1;
				sum.m_nUnsignedData[i] -= 10;
			}
			else carryFlag = 0;
		}
	}
	else {
		// 异号情形
		if (abs(n1) > abs(n2)) {
			sum.m_cSign = n1.m_cSign;
			bool carryFlag = 0;// 借位
			for (int i = 0; i < 110; i++) {// 由低位到高位
				sum.m_nUnsignedData[i] = n1.m_nUnsignedData[i] - n2.m_nUnsignedData[i] - carryFlag;
				if (sum.m_nUnsignedData[i] < 0) {
					carryFlag = 1;
					sum.m_nUnsignedData[i] += 10;
				}
			}
		}
		else {
			sum.m_cSign = n2.m_cSign;
			bool carryFlag = 0;// 借位
			for (int i = 0; i < 110; i++) {// 由低位到高位
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

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
