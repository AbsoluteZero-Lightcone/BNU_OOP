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
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const IntArray& source : 待输出的对象
  * @retval ostream& 实现链式编程
  */
ostream& operator<<(ostream& out, const IntArray& source) {
	
	return out;
}

/**
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param IntArray& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
  */
istream& operator>>(istream& input, IntArray& target)
{
	cout << "input:";
	return input;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
