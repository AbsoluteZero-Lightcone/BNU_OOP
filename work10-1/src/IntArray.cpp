/**
  ******************************************************************************
  * @file    IntArray.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-13
  * @brief   IntArray class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "IntArray.h"

/* Constructors & Deconstructor --------------------------------------------- */
IntArray::IntArray(int t_nSize) {
	if (t_nSize < 1) {
		cout << "Error dimension description";
		exit(1);
	}
	m_nSize = t_nSize;
	m_ptrData = new int[m_nSize];
}

IntArray::~IntArray() {
	if (m_ptrData != nullptr) {
		delete[] m_ptrData;
	}
	m_ptrData = nullptr;
}

int IntArray::size() const{ return m_nSize; }

int& IntArray::operator[](int index) {
	index = index - 1;//�����±��1��ʼ
	if (index < 0 || index >= m_nSize) {
		cerr << "Index out of range." << endl;
		delete[] m_ptrData;
		m_ptrData = nullptr;
		exit(2);
	}
	return m_ptrData[index];
}


/* Getters & Setters -------------------------------------------------------- */

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const IntArray& source : ������Ķ���
  * @retval ostream& ʵ����ʽ���
  */
ostream& operator<<(ostream& out, const IntArray& source) {
	out << "{";
	for (int i = 0; i < source.m_nSize; i++) {
		out << source.m_ptrData[i];
		if (i != source.m_nSize - 1) {
			out << ", ";
		}
	}
	out << "}";
	return out;
}

/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param IntArray& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, IntArray& target) {
	cout << "input:";
	return input;
}

bool operator==(const IntArray& a, const IntArray& b) {
	return false;
}

bool operator!=(const IntArray& a, const IntArray& b) {
	return !(a == b);
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
