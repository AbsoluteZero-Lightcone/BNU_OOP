/**
  ******************************************************************************
  * @file    ExpressionOperator.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-20
  * @brief   ExpressionOperator
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXPRESSIONOPERATOR_H
#define __EXPRESSIONOPERATOR_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
#include "ExpressionElement_Base.h"
class ExpressionOperator :public ExpressionElement_Base {
	char m_cOperator;
public:
	void fetch(string& s) {
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
	friend ostream& operator<<(ostream& out, const ExpressionOperator& e);
};

ostream& operator<<(ostream& out, const ExpressionOperator& e) {
	out << e.m_cOperator;
	return out;
}
/* Exported functions ------------------------------------------------------- */

#endif /* !__EXPRESSIONOPERATOR_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
