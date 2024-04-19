/**
  ******************************************************************************
  * @file    main.cpp
  * @author  张亦法
  * @date    2024-04-19
  * @brief   入口函数
  ******************************************************************************
  */
#include <fstream>
#include <string>
#include <iostream>
#include <cstdint>
using namespace std;

int getStringLength(const char* str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

class Sum {
public:
	Sum() {}
	virtual ~Sum() {}
	virtual void Show() = 0;
	virtual void Add(Sum* num) = 0;
};
class Number :public Sum {
private:
	double m_dData;
public:
};
class Complex :public Sum {
private:
	double m_dReal;
	double m_dImag;
public:
};
class Fraction :public Sum {
private:
	int m_nNum;
	int m_nDen;
public:
};
class Huge_Int :public Sum {
private:
	char m_cSign;
	int m_nUnsignedData[110] = { 0 };// 存储顺序小端在低位
	// 阅读顺序小端在高位
public:
	Huge_Int(const char* str = "0") {
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
	~Huge_Int() {}
	void Show() {
		if (m_cSign == '-')cout << '-';
		bool started = 0;// 判断是否到有效数字区
		for (int i = 110 - 1; i >= 0; i--) {
			if (!started)
				if (m_nUnsignedData[i] == 0)
					continue;
				else started = 1;
			cout << m_nUnsignedData[i];
		}
	}
	void Add(Sum* num) {
		if (typeid(*num) == typeid(class Huge_Int)) {
			Huge_Int* huge_num = (Huge_Int*)num;
			bool carryFlag = 0;// 进位
			for (int i = 0; i < 110; i++) {
				if (huge_num->m_cSign == m_cSign) {
					m_nUnsignedData[i] += huge_num->m_nUnsignedData[i] + carryFlag;
					if (m_nUnsignedData[i] >= 10) {
						carryFlag = 1;
						m_nUnsignedData[i] -= 10;
					}
					else carryFlag = 0;
				}
			}
		}
		Show();
	}

};
int main()
{
	Sum* ps1, * ps2;
	//cout << typeid(class Huge_Int).name() << endl;
	// 
	//Number a(25.0), b(30.5);
	//ps1 = &a; ps2 = &b;
	//ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	//Complex ca(1, 2), cb(3, 4);
	//ps1 = &ca; ps2 = &cb;
	//ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	//Fraction fa(2, 3), fb(3, 4);
	//ps1 = &fa; ps2 = &fb;
	//ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	Huge_Int ha("+12345678901234567890"), hb("+99999999999999999999");
	ps1 = &ha; ps2 = &hb;
	ps1->Show(); cout << " + "; ps2->Show(); cout << " = "; ps1->Add(ps2); cout << endl;

	return 0;
}

/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
