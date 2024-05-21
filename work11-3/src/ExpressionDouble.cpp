/**
  ******************************************************************************
  * @file    ExpressionDouble.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.0.0
  * @date    2024-05-20
  * @brief   ExpressionDouble
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "ExpressionDouble.h"
#include <cassert>
/* Exported functions ------------------------------------------------------- */
ExpressionDouble::ExpressionDouble(double d) :m_dData(d) {}
ExpressionDouble::ExpressionDouble(string s) { fetch(s); /* 实参不变 */ }
ExpressionDouble::ExpressionDouble(const ExpressionDouble& e) : m_dData(e.m_dData) {}

ExpressionDouble& ExpressionDouble::operator=(const ExpressionDouble& e) {
	m_dData = e.m_dData;
	return *this;
}

ExpressionDouble::operator double() const{
	return m_dData;
}

/**
  * @brief 从字符串中提取一个浮点数，字符串中的第一个浮点数被提取出来，字符串被修改为去掉提取的部分
  * @param s 字符串
  * @retval None
  */
void ExpressionDouble::fetch(string& s) {
	assert(s.length() > 0);
	m_dData = 0;
	int i = 0;
	while (s[i] >= '0' && s[i] <= '9') { // 整数部分
		m_dData = m_dData * 10 + (s[i] - '0');
		i++;
		if (i >= s.length())break;
	}
	if (s[i] == '.') { // 小数部分
		// 允许没有整数部分 .123 == 0.123
		// 也允许没有小数部分 123. == 123
		i++;
		double weight = 0.1; // 位权
		while (s[i] >= '0' && s[i] <= '9') {
			m_dData += weight * (s[i] - '0');
			weight *= 0.1;
			i++;
			if (i >= s.length())break;
		}
	}
	s = s.substr(i);
}
ostream& operator<<(ostream& out, const ExpressionDouble& e) {
	out << e.m_dData;
	return out;
}

ExpressionDouble operator+(const ExpressionDouble& a, const ExpressionDouble& b) {
	return ExpressionDouble(a.m_dData + b.m_dData);
}
ExpressionDouble operator-(const ExpressionDouble& a, const ExpressionDouble& b) {
	return ExpressionDouble(a.m_dData - b.m_dData);
}
ExpressionDouble operator*(const ExpressionDouble& a, const ExpressionDouble& b) {
	return ExpressionDouble(a.m_dData * b.m_dData);
}
ExpressionDouble operator/(const ExpressionDouble& a, const ExpressionDouble& b) {
	if (b.m_dData == 0) throw "Divided by zero.";
	return ExpressionDouble(a.m_dData / b.m_dData);
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
