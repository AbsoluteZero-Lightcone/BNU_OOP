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


IntArray::IntArray()
{
}

IntArray::IntArray(int t_nSize)
{
}

IntArray::~IntArray() {}


/* Getters & Setters -------------------------------------------------------- */

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ���ر�׼����� <<�����
  * @param ostream& out : ��׼���������
  * @param const IntArray& source : ������Ķ���
  * @retval ostream& ʵ����ʽ���
  */
ostream& operator<<(ostream& out, const IntArray& source) {
	
	return out;
}

/**
  * @brief ���ر�׼������ >>�����
  * @param istream& input : ��׼���������
  * @param IntArray& target : �����������ݵĶ���
  * @retval istream& ʵ����ʽ���
  */
istream& operator>>(istream& input, IntArray& target)
{
	cout << "input:";
	return input;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
