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
MySet::MySet() :_count(0) {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief
  * @param
  * @retval
  */
int& MySet::operator[](unsigned i){}
/**
  * @brief
  * @param
  * @retval
  */
bool MySet::IsInSet(int x) const{}
/**
  * @brief
  * @param
  * @retval
  */
MySet MySet::operator+(const MySet& n2) const{}
/**
  * @brief
  * @param
  * @retval
  */
MySet MySet::operator-(const MySet& n2) const{}
/**
  * @brief
  * @param
  * @retval
  */
MySet& MySet::operator++(){}
/**
  * @brief
  * @param
  * @retval
  */
MySet MySet::operator++(int){}
/**
  * @brief
  * @param
  * @retval
  */
MySet& operator--(MySet& source){}
/**
  * @brief
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
