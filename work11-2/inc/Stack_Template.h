/**
  ******************************************************************************
  * @file    Stack_Template.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-16
  * @brief   Stack class
  * @encode  GB2312
  ******************************************************************************
  */
#ifndef __STACK_TEMPLATE_H
#define __STACK_TEMPLATE_H
  /* Includes ------------------------------------------------------------------*/
#include "Stack.h"

/* Constructors & Deconstructor --------------------------------------------- */
template<class T>
Stack<T>::Stack() :
	m_nSize(0),
	m_ptrData(nullptr)
{}

template<class T>
Stack<T>::Stack(const Stack<T>& source) {
	m_ptrData = new T[source.m_nSize];
	for (int i = 0; i < source.m_nSize; i++) {
		m_ptrData[i] = source.m_ptrData[i];
	}
	m_nSize = source.m_nSize;
}

template<class T>
Stack<T>::~Stack() {
	delete[] m_ptrData;
	m_ptrData = nullptr;
}

/* Getters ------------------------------------------------------------------ */
template<typename T>
T& Stack<T>::operator[](int t_nIndex) const {
	//if (t_nIndex < 0 || t_nIndex >= m_nSize) {
	//	throw out_of_range("out of range");
	//}
	// ����[]�����壬��Ӧ���б߽���
	return m_ptrData[t_nIndex];
}

template<typename T>
T& Stack<T>::at(int t_nIndex) const {
	if (t_nIndex < 0 || t_nIndex >= m_nSize) {
		throw out_of_range("out of range");
	}// at�������б߽���
	return m_ptrData[t_nIndex];
}

template<class T>
T& Stack<T>::front() const { return m_ptrData[0]; }

template<typename T>
T& Stack<T>::back() const { return m_ptrData[m_nSize - 1]; }

template<typename T>
T& Stack<T>::top() const { return m_ptrData[m_nSize - 1]; }

template<class T>
T& Stack<T>::bottom() const { return m_ptrData[0]; }

template<class T>
T* Stack<T>::data() const { return m_ptrData; }

template<class T>
int Stack<T>::size() const { return m_nSize; }

template<class T>
bool Stack<T>::isEmpty() const { return m_nSize == 0; }

/* Operations --------------------------------------------------------------- */

/**
  * @brief ��ջ
  * @retval T : ��ջ������
  */
template<typename T>
T Stack<T>::pop() {
	if (m_nSize == 0) {
		throw out_of_range("out of range");
	}
	T temp = m_ptrData[m_nSize - 1];
	resize(m_nSize - 1);
	return temp;
}

/**
  * @brief ѹջ
  * @param const T& t_data : ��ѹջ������
  * @retval Stack<T>& : ѹջ���ջ, ������ʽ����
  */
template<typename T>
Stack<T>& Stack<T>::push(const T& t_data) {
	resize(m_nSize + 1);
	m_ptrData[m_nSize - 1] = t_data;
	return *this;
}

template<class T>
Stack<T>& Stack<T>::operator>>(T& pop){
	pop = this->pop();
	return *this;
}

template<class T>
Stack<T>& Stack<T>::operator<<(const T& push){
	this->push(push);
	return *this;
}

/**
  * @brief ���ջ
  * @retval None
  */
template<class T>
void Stack<T>::clear() {
	delete[] m_ptrData;
	m_ptrData = nullptr;
	m_nSize = 0;
}

/**
  * @brief �ı�ջ�Ĵ�С
  * @param int t_nSize : �µ�ջ��С
  * @retval Stack<T>& : �ı��С���ջ, ������ʽ����
  */
template<class T>
Stack<T>& Stack<T>::resize(int t_nSize) {
	T* temp = new T[t_nSize];
	for (int i = 0; i < t_nSize && i < m_nSize; i++) {
		temp[i] = m_ptrData[i];
	}
	// ������Ĳ��ֳ�ʼ��Ϊ0
	delete[] m_ptrData;
	m_ptrData = temp;
	m_nSize = t_nSize;
	return *this;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Stack& source : ������ֵ
  * @retval ��
  */
template<class T>
void Stack<T>::operator=(const Stack<T>& source) {
	delete[] m_ptrData;
	m_ptrData = new T[source.m_nSize];
	for (int i = 0; i < source.m_nSize; i++) {
		m_ptrData[i] = source.m_ptrData[i];
	}
	m_nSize = source.m_nSize;
}

/**
  * @brief ���ر�׼������ >>�����
  * @param istream& in : ��׼����������
  * @param const Stack<T>& source : ������Ķ���
  * @retval istream&
  */
template<class T>
istream& operator>>(istream& in, Stack<T>& source) {
	T temp;
	in >> temp;
	source.push(temp);
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Stack<T>& source : ������Ķ���
  * @retval ostream&
  */
template<class T>
ostream& operator<<(ostream& out, const Stack<T>& source) {
	out << "stack:[";
	for (int i = 0; i < source.size(); i++) {
		out << source[i];
		if (i != source.size() - 1) {
			out << ",";
		}
	}
	out << "]";
	return out;
}

/**
  * @brief ���ص��������
  * @param const Stack& n1 : �������ߵ�ֵ
  * @param const Stack& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
template<class T>
bool operator==(const Stack<T>& n1, const Stack<T>& n2) {
	if (n1.m_nSize != n2.m_nSize)return false;
	for (int i = 0; i < n1.m_nSize; i++)
		if (n1.m_ptrData[i] != n2.m_ptrData[i])
			return false;
	return true;
}

/**
  * @brief ���ز����������
  * @param const Stack& n1 : �������ߵ�ֵ
  * @param const Stack& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 != n2
  */
template<class T>
bool operator!=(const Stack<T>& n1, const Stack<T>& n2) {return !(n1 == n2);}

#endif // /* !__STACK_TEMPLATE_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
