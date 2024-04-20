/**
  ******************************************************************************
  * @file    exported_class.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   exported_class class
  * @encode  GB2312
  ******************************************************************************
  */

#include "exported_class.h"

exported_class::exported_class() {}
exported_class::exported_class(const exported_class& source) {}
exported_class::~exported_class() {}

datatype1 exported_class::get_dataname1() { return m_dataname1; }
void exported_class::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 exported_class::get_dataname2() { return m_dataname2; }
void exported_class::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }

/**
  * @brief ��������ͨ������ֵ�ĸ�ֵ�����
  * @param const exported_class& source : ������ֵ
  * @retval ��
  */
void exported_class::operator=(const exported_class& source) {
	// todo
}

/**
  * @brief ��������ʹ��������ֵ�ĸ�ֵ�����
  * @param int n : ������ֵ
  * @retval ��
  */
void exported_class::operator=(int n) {
	// todo
}

/**
  * @brief ��������+=�����
  * @param n : ���ӵ�ֵ
  * @retval ������������ʵ����ʽ���
  */
exported_class& exported_class::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief �����������������
  * @param ��
  * @retval ������������ʵ����ʽ���
  */
exported_class& exported_class::operator++() {
	// todo
	return *this;
}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const exported_class& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const exported_class& source) {
	// todo
	return out;
}

/**
  * @brief ���ش��������
  * @param const exported_class& n1 : �������ߵ�ֵ
  * @param const exported_class& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 > n2
  */
bool operator>(const exported_class& n1, const exported_class& n2) {
	// todo
	return false;
}

/**
  * @brief ���ص��������
  * @param const exported_class& n1 : �������ߵ�ֵ
  * @param const exported_class& n2 : ������ұߵ�ֵ
  * @retval bool, true for n1 == n2
  */
bool operator==(const exported_class& n1, const exported_class& n2) {
	// todo
	return false;
}

/**
  * @brief ���ظ���
  * @param exported_class n : ֵ���ݴ�ȡ����ֵ
  * @retval -n
  */
exported_class operator-(exported_class n) {
	// todo
	return n;
}

/**
  * @brief ���ؼӷ������
  * @param const exported_class& n1 : �Ӻ���ߵ�ֵ
  * @param const exported_class& n2 : �Ӻ��ұߵ�ֵ
  * @retval n1 + n2
  */
exported_class operator+(const exported_class& n1, const exported_class& n2) {
	exported_class temp;
	// todo
	return temp;
}

/**
  * @brief ���ؼ��������
  * @param const exported_class& n1 : ������
  * @param const exported_class& n2 : ����
  * @retval n1 - n2
  */
exported_class operator-(const exported_class& n1, const exported_class& n2) {
	exported_class temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
