/**
  ******************************************************************************
  * @file    ExpressionBrackets.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.1.1
  * @date    2024-05-20
  * @brief   ExpressionBrackets
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "ExpressionBrackets.h"
#include <cassert>
/* Exported functions ------------------------------------------------------- */

ExpressionBrackets::ExpressionBrackets(char c) : m_cOperator(c) {}
ExpressionBrackets::ExpressionBrackets(string s) { fetch(s); /* ʵ�β��� */ }
ExpressionBrackets::ExpressionBrackets(const ExpressionBrackets& e) : m_cOperator(e.m_cOperator) {}
ExpressionBrackets& ExpressionBrackets::operator=(const ExpressionBrackets& e) {
	m_cOperator = e.m_cOperator;
	return *this;
}


/**
  * @brief ���ַ�������ȡ����
  * @param s �ַ���
  * @retval None
  */
void ExpressionBrackets::fetch(string& s) {
	assert(s.length() > 0);
	assert(
		s[0] == '(' ||
		s[0] == ')'
	);
	m_cOperator = s[0];
	s = s.substr(1);
}

char ExpressionBrackets::getOperator() const{
	return m_cOperator;
}


ostream& operator<<(ostream& out, const ExpressionBrackets& e) {
	out << e.m_cOperator;
	return out;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
