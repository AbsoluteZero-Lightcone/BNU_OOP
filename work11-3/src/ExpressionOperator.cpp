/**
  ******************************************************************************
  * @file    ExpressionOperator.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-20
  * @brief   ExpressionOperator
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "ExpressionOperator.h"
#include <cassert>
/* Exported functions ------------------------------------------------------- */

ExpressionDouble ExpressionOperator::calculate(ExpressionDouble a, ExpressionDouble b) {
	switch (m_cOperator) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
	throw "Invalid Operator.";
}

/**
  * @brief ´Ó×Ö·û´®ÖÐÌáÈ¡ÔËËã·û
  * @param s ×Ö·û´®
  * @retval None
  */
void ExpressionOperator::fetch(string& s) {
	assert(s.length() > 0);
	assert(
		s[0] == '+' ||
		s[0] == '-' ||
		s[0] == '*' ||
		s[0] == '/' ||
		s[0] == '(' ||
		s[0] == ')'
	);
	m_cOperator = s[0];
	s = s.substr(1);
}


ostream& operator<<(ostream& out, const ExpressionOperator& e) {
	out << e.m_cOperator;
	return out;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
