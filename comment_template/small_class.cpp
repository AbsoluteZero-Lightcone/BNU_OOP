/**
  ******************************************************************************
  * @file    small_class.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   small_class class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "small_class.h"

/* Constructors & Deconstructor --------------------------------------------- */
small_class::small_class() :
	m_dataname1(0),
	m_dataname2(0)
{}

small_class::small_class(datatype1 t_dataname1, datatype2 t_dataname2) :
	m_dataname1(t_dataname1),
	m_dataname2(t_dataname2)
{}

small_class::small_class(const small_class& source) :
	m_dataname1(source.m_dataname1),
	m_dataname2(source.m_dataname2)
{}

small_class::~small_class() {}

/* Getters & Setters -------------------------------------------------------- */
datatype1 small_class::get_dataname1()const { return m_dataname1; }
void small_class::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 small_class::get_dataname2()const { return m_dataname2; }
void small_class::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const small_class& source : ������ֵ
  * @retval ��
  */
void small_class::operator=(const small_class& source) {
	m_dataname1 = source.m_dataname1;
	m_dataname2 = source.m_dataname2;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const small_class& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const small_class& source) {
	// todo
	return out;
}

/**
  * @brief ���ص��������
  * @param const small_class& n1 : �������ߵ�ֵ
  * @param const small_class& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const small_class& n1, const small_class& n2) {
	if (n1.m_dataname1 != n2.m_dataname1)return false;
	if (n1.m_dataname2 != n2.m_dataname2)return false;
	return false;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
