/**
  ******************************************************************************
  * @file    Teacher.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Teacher class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Teacher.h"

/* Constructors & Deconstructor --------------------------------------------- */
Teacher::Teacher() :
	m_strName(0)
{}

Teacher::Teacher(string t_strName) :
	m_strName(t_strName)
{}

Teacher::Teacher(const Teacher& source) :
	m_strName(source.m_strName)
{}

Teacher::~Teacher() {}

/* Getters & Setters -------------------------------------------------------- */
string Teacher::get_strName()const { return m_strName; }
void Teacher::set_strName(string t_strName) { m_strName = t_strName; }

/* Private functions -------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Teacher& source : 待赋的值
  * @retval 无
  */
void Teacher::operator=(const Teacher& source) {
	m_strName = source.m_strName;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Teacher& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Teacher& source) {
	// todo
	return out;
}

/**
  * @brief 重载等于运算符
  * @param const Teacher& n1 : 运算符左边的值
  * @param const Teacher& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Teacher& n1, const Teacher& n2) {
	if (n1.m_strName != n2.m_strName)return false;
	return false;
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
