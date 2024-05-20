/**
  ******************************************************************************
  * @file    ExpressionOperator.h
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
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
using namespace std;
#include "ExpressionElement_Base.h"
#include "ExpressionDouble.h"
/* Class ---------------------------------------------------------------------*/
class ExpressionOperator :public ExpressionElement_Base {
	char m_cOperator;
public:
	ExpressionOperator(char c = '+');
	ExpressionOperator(string s);
	ExpressionOperator(const ExpressionOperator& e);
	ExpressionOperator& operator=(const ExpressionOperator& e);

	void fetch(string& s);
	int getPriority()const;
	ExpressionDouble operate(const ExpressionDouble& a, const ExpressionDouble& b);
	friend ostream& operator<<(ostream& out, const ExpressionOperator& e);
};
/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const ExpressionOperator& e);

#endif /* !__EXPRESSIONOPERATOR_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
