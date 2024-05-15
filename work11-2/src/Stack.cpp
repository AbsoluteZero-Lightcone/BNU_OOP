/**
  ******************************************************************************
  * @file    Stack.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-15
  * @brief   Stack class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Stack.h"

/* Constructors & Deconstructor --------------------------------------------- */
template<class T>
Stack<T>::Stack() :
	m_nSize(0),
	m_ptrData(nullptr)
{}

template<class T>
Stack<T>::Stack(int t_nSize, T* t_ptrData) :
	m_nSize(t_nSize),
	m_ptrData(t_ptrData)
{}
template<class T>
Stack<T>::Stack(const Stack<T>& source) :
	m_nSize(source.m_nSize),
	m_ptrData(source.m_ptrData)
{}
template<class T>
Stack<T>::~Stack() {}

/* Getters ------------------------------------------------------------------ */

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const Stack& source : ������ֵ
  * @retval ��
  */
template<class T>
void Stack<T>::operator=(const Stack<T>& source) {
	m_nSize = source.m_nSize;
	m_ptrData = source.m_ptrData;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const Stack& source : ������Ķ���
  * @retval ostream&
  */
template<class T>
ostream& operator<<(ostream& out, const Stack<T>& source) {
	// todo
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
	if (n1.m_ptrData != n2.m_ptrData)return false;
	return true;
}

/**
  * @brief ���ز����������
  * @param const Stack& n1 : �������ߵ�ֵ
  * @param const Stack& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 != n2
  */
template<class T>
bool operator!=(const Stack<T>& n1, const Stack<T>& n2) {
	if (n1.m_nSize == n2.m_nSize)return false;
	if (n1.m_ptrData == n2.m_ptrData)return false;
	return true;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
