/**
  ******************************************************************************
  * @file    ExpressionBrackets.h
  * @author  Zhang Yifa 202311998186
  * @version V2.1.0
  * @date    2024-05-20
  * @brief   ExpressionBrackets
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXPRESSIONBRACKETS_H
#define __EXPRESSIONBRACKETS_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "ExpressionElement_Base.h"
/* Class ---------------------------------------------------------------------*/
class ExpressionBrackets :public ExpressionElement_Base {
	char m_cOperator;
public:
	ExpressionBrackets(char c = '(');
	ExpressionBrackets(string s);
	ExpressionBrackets(const ExpressionBrackets& e);
	ExpressionBrackets& operator=(const ExpressionBrackets& e);

	void fetch(string& s);
	char getOperator()const;
	friend ostream& operator<<(ostream& out, const ExpressionBrackets& e);
};
/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const ExpressionBrackets& e);

#endif /* !__EXPRESSIONBRACKETS_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
