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
	index = index - 1;//数组下标从1开始
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
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const IntArray& source : 待输出的对象
  * @retval ostream& 实现链式编程
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
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param IntArray& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
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
