/**
  ******************************************************************************
  * @file    multi_candidate_class.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   multi_candidate_class class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "multi_candidate_class.h"

/* Constructors & Deconstructor --------------------------------------------- */
multi_candidate_class::multi_candidate_class() :
	m_dataname1(0),
	m_dataname2(0),
	m_dataname3(0),
	m_dataname4(0),
	m_dataname5(0),
	m_dataname6(0)
{}

multi_candidate_class::multi_candidate_class(
	datatype1 t_dataname1,
	datatype2 t_dataname2,
	datatype3 t_dataname3,
	datatype4 t_dataname4,
	datatype5 t_dataname5,
	datatype6 t_dataname6
) :
	m_dataname1(t_dataname1),
	m_dataname2(t_dataname2),
	m_dataname3(t_dataname3),
	m_dataname4(t_dataname4),
	m_dataname5(t_dataname5),
	m_dataname6(t_dataname6)
{}

multi_candidate_class::~multi_candidate_class() {}

/* Getters & Setters -------------------------------------------------------- */
datatype1 multi_candidate_class::get_dataname1()const { return m_dataname1; }
datatype2 multi_candidate_class::get_dataname2()const { return m_dataname2; }
datatype3 multi_candidate_class::get_dataname3()const { return m_dataname3; }
datatype4 multi_candidate_class::get_dataname4()const { return m_dataname4; }
datatype5 multi_candidate_class::get_dataname5()const { return m_dataname5; }
datatype6 multi_candidate_class::get_dataname6()const { return m_dataname6; }
void multi_candidate_class::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
void multi_candidate_class::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }
void multi_candidate_class::set_dataname3(datatype3 t_dataname3) { m_dataname3 = t_dataname3; }
void multi_candidate_class::set_dataname4(datatype4 t_dataname4) { m_dataname4 = t_dataname4; }
void multi_candidate_class::set_dataname5(datatype5 t_dataname5) { m_dataname5 = t_dataname5; }
void multi_candidate_class::set_dataname6(datatype6 t_dataname6) { m_dataname6 = t_dataname6; }

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const multi_candidate_class& source : 待输出的对象
  * @retval ostream& 实现链式编程
  */
ostream& operator<<(ostream& out, const multi_candidate_class& source) {
	// todo
	return out;
}

/**
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param multi_candidate_class& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
  */
istream& operator>>(istream& input, multi_candidate_class& target)
{
	cout << "input:";
	input 
		>> target.m_dataname1 
		>> target.m_dataname2 
		>> target.m_dataname3 
		>> target.m_dataname4 
		>> target.m_dataname5 
		>> target.m_dataname6;
	return input;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
