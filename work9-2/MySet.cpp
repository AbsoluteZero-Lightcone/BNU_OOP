/**
  ******************************************************************************
  * @file    MySet.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   MySet class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "MySet.h"

/* Constructors & Deconstructor --------------------------------------------- */
/**
  * @brief �޲ι��캯�����������ϣ���Ԫ�ظ�����Ϊ0.
  * @param None
  */
MySet::MySet() :_count(0) {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief �����±������
  */
int& MySet::operator[](unsigned i){}

/**
  * @brief �ж�����x�Ƿ��Ǽ��ϵ�Ԫ��
  * @param int x
  * @retval bool
  */
bool MySet::IsInSet(int x) const{}

/**
  * @brief �������϶���ļӷ����㡱+���������Ǻϲ���������
  * @param
  * @retval
  */
MySet MySet::operator+(const MySet& n2) const{}

/**
  * @brief �������϶���ļ������㡱-�����������������1�еĲ����ڼ���2��Ԫ��
	��������Ҫ����ο�����ע�͡�
  * @param
  * @retval
  */
MySet MySet::operator-(const MySet& n2) const{}

/**
  * @brief ���ϵġ�ǰ��++�����㣬�����ǽ������е�ÿһ��Ԫ������1��ǰ��������
  * @param
  * @retval
  */
MySet& MySet::operator++(){}
/**
  * @brief ���ϵġ�����++�����㣬�����ǽ������е�ÿһ��Ԫ������1������������
  * @param
  * @retval
  */
MySet MySet::operator++(int){}
/**
  * @brief ��Ԫ�����ϵġ�ǰ��--�����㣬�����ǽ������е�ÿһ��Ԫ���Լ�1��ǰ���Լ���
  * @param
  * @retval
  */
MySet& operator--(MySet& source){}
/**
  * @brief ��Ԫ�����ϵġ�����--�����㣬�����ǽ������е�ÿһ��Ԫ���Լ�1�������Լ���
  * @param
  * @retval
  */
MySet operator--(MySet& source, int){}

/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const MySet& source : ������Ķ���
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const MySet& source){
}
/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param MySet& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, MySet& target){
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
