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
void exported_class::operator=(const exported_class& source) {}
datatype1 exported_class::get_dataname1() { return m_dataname1; }
void exported_class::set_dataname1(datatype1 t_dataname1) { m_dataname1 = t_dataname1; }
datatype2 exported_class::get_dataname2() { return m_dataname2; }
void exported_class::set_dataname2(datatype2 t_dataname2) { m_dataname2 = t_dataname2; }

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const exported_class& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const exported_class& source) {

	return out;
}
/**
  * @brief 重载大于运算符
  * @param const exported_class& n1 : 运算符左边的值
  * @param const exported_class& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const exported_class& n1, const exported_class& n2){}
bool operator==(const exported_class& n1, const exported_class& n2){}
exported_class operator-(exported_class n){}
exported_class operator+(const exported_class& n1, const exported_class& n2){}
exported_class operator-(const exported_class& n1, const exported_class& n2){}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
