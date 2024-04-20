/**
  ******************************************************************************
  * @file    Huge_Int.h
  * @author  ���෨ 202311998186
  * @date    2024-04-19
  * @brief   �߾�����������
  ******************************************************************************
  */
#ifndef __HUGE_INT_H
#define __HUGE_INT_H

#include <iostream>
using namespace std;
#include "Sum.h"

class Huge_Int :public Sum {
private:
	char m_cSign;
	int m_nUnsignedData[110] = { 0 };// �洢˳��С���ڵ�λ
	// �Ķ�˳��С���ڸ�λ
public:
	Huge_Int(const char* str = "0");
	~Huge_Int();

	void operator=(const Huge_Int& n);
	friend ostream& operator<<(ostream& out, const Huge_Int& n);
	friend Huge_Int operator+(const Huge_Int& n1, const Huge_Int& n2);
	friend bool operator>(const Huge_Int& n1, const Huge_Int& n2);
	friend Huge_Int operator-(Huge_Int n);
	friend Huge_Int abs(Huge_Int n);


	// �涨����
	void Show();
	void Add(Sum* num);
};
ostream& operator<<(ostream& out, const Huge_Int& n);
bool operator>(const Huge_Int& n1, const Huge_Int& n2);
Huge_Int operator-(Huge_Int n);
Huge_Int abs(Huge_Int n);
Huge_Int operator+(const Huge_Int& n1, const Huge_Int& n2);
Huge_Int operator-(const Huge_Int& n1, const Huge_Int& n2);

#endif // !__HUGE_INT_H
/******************* Absolute Zero Studio - Lightcone **********END OF FILE****/
