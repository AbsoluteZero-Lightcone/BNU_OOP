/**
  ******************************************************************************
  * @file    small_3_class.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   small_3_class class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "small_3_class.h"

/* Constructors & Deconstructor --------------------------------------------- */
small_3_class::small_3_class() :
	m_dataname1(0),
	m_dataname2(0),
	m_dataname3(0)
{}

small_3_class::small_3_class(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3) :
	m_dataname1(t_dataname1),
	m_dataname2(t_dataname2),
	m_dataname3(t_dataname3)
{}

small_3_class::small_3_class(const small_3_class& source) :
	m_dataname1(source.m_dataname1),
	m_dataname2(source.m_dataname2),
	m_dataname3(source.m_dataname3)
{}

small_3_class::~small_3_class() {}

/* Getters & Setters -------------------------------------------------------- */
datatype1 small_3_class::get_dataname1()const { return m_dataname1; }
void small_3_class::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 small_3_class::get_dataname2()const { return m_dataname2; }
void small_3_class::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }
datatype3 small_3_class::get_dataname3()const { return m_dataname3; }
void small_3_class::set_dataname3(datatype3 t_dataname3) { m_dataname3 = t_dataname3; }
void small_3_class::set(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3) {
	m_dataname1 = t_dataname1; m_dataname2 = t_dataname2; m_dataname3 = t_dataname3;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const small_3_class& source : ������ֵ
  * @retval ��
  */
void small_3_class::operator=(const small_3_class& source) {
	m_dataname1 = source.m_dataname1;
	m_dataname2 = source.m_dataname2;
	m_dataname3 = source.m_dataname3;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const small_3_class& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const small_3_class& source) {
	// todo
	return out;
}

/**
  * @brief ���ص��������
  * @param const small_3_class& n1 : �������ߵ�ֵ
  * @param const small_3_class& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const small_3_class& n1, const small_3_class& n2) {
	if (n1.m_dataname1 != n2.m_dataname1)return false;
	if (n1.m_dataname2 != n2.m_dataname2)return false;
	if (n1.m_dataname3 != n2.m_dataname3)return false;
	return true;
}

/**
  * @brief ���ز����������
  * @param const small_3_class& n1 : �������ߵ�ֵ
  * @param const small_3_class& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 != n2
  */
bool operator!=(const small_3_class& n1, const small_3_class& n2) {
	if (n1.m_dataname1 == n2.m_dataname1)return false;
	if (n1.m_dataname2 == n2.m_dataname2)return false;
	if (n1.m_dataname3 == n2.m_dataname3)return false;
	return true;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
