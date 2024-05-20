/**
  ******************************************************************************
  * @file    ExpressionOperator.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.2.0
  * @date    2024-05-20
  * @brief   ExpressionOperator
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "ExpressionOperator.h"
#include <cassert>
/* Exported functions ------------------------------------------------------- */

ExpressionOperator::ExpressionOperator(char c) : m_cOperator(c) {}
ExpressionOperator::ExpressionOperator(string s) { fetch(s); /* 实参不变 */ }
ExpressionOperator::ExpressionOperator(const ExpressionOperator& e) : m_cOperator(e.m_cOperator) {}
ExpressionOperator& ExpressionOperator::operator=(const ExpressionOperator& e) {
	m_cOperator = e.m_cOperator;
	return *this;
}

/**
  * @brief 取得运算符优先级，数字越大优先级越高
  */
int ExpressionOperator::getPriority() const{
	switch (m_cOperator) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		throw "Invalid Operator.";
	}
}

ExpressionDouble ExpressionOperator::operate(const ExpressionDouble& a, const ExpressionDouble& b) {
	switch (m_cOperator) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		throw "Invalid Operator.";
	}
}

/**
  * @brief 从字符串中提取运算符
  * @param s 字符串
  * @retval None
  */
void ExpressionOperator::fetch(string& s) {
	assert(s.length() > 0);
	assert(
		s[0] == '+' ||
		s[0] == '-' ||
		s[0] == '*' ||
		s[0] == '/' 
	);
	m_cOperator = s[0];
	s = s.substr(1);
}


ostream& operator<<(ostream& out, const ExpressionOperator& e) {
	out << e.m_cOperator;
	return out;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
