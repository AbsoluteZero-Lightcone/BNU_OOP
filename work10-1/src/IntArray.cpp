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

IntArray::IntArray(const IntArray& source){
	m_nSize = source.m_nSize;
	m_ptrData = new int[m_nSize];
	for (int i = 0; i < m_nSize; i++) {
		m_ptrData[i] = source.m_ptrData[i];
	}
}

IntArray::~IntArray() {
	if (m_ptrData != nullptr) {
		delete[] m_ptrData;
	}
	m_ptrData = nullptr;
}

int IntArray::size() const{ return m_nSize; }

void IntArray::resize(int t_nSize){
	if (t_nSize < 1) {
		cout << "Error dimension description";
		exit(1);
	}
	int* temp = new int[t_nSize];
	int minSize = (t_nSize > m_nSize) ? m_nSize : t_nSize;
	for (int i = 0; i < minSize; i++) {
		temp[i] = m_ptrData[i];
		// ʣ�ಿ�ֳ�ʼ��Ϊ0
	}
	delete[] m_ptrData;
	m_ptrData = temp;
	m_nSize = t_nSize;
}

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

void IntArray::operator=(const IntArray& source){
	if (this == &source) {
		return;
	}
	if (m_ptrData != nullptr) {
		delete[] m_ptrData, m_ptrData=nullptr;
	}
	m_nSize = source.m_nSize;
	m_ptrData = new int[m_nSize];
	for (int i = 0; i < m_nSize; i++) {
		m_ptrData[i] = source.m_ptrData[i];
	}
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
	for (int i = 0; i < target.m_nSize; i++) {
		input >> target.m_ptrData[i];
	}
	return input;
}

bool operator==(const IntArray& a, const IntArray& b) {
	if (a.m_nSize != b.m_nSize) {
		return false;
	}
	for (int i = 0; i < a.m_nSize; i++) {
		if (a.m_ptrData[i] != b.m_ptrData[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const IntArray& a, const IntArray& b) {
	return !(a == b);
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
