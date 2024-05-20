/**
  ******************************************************************************
  * @file    Expression.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-20
  * @brief   Expression
  * @encode  GB2312
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXPRESSION_H
#define __EXPRESSION_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"
#include "ExpressionDouble.h"
#include "ExpressionOperator.h"
#include "ExpressionElement_Base.h"

/* Class ---------------------------------------------------------------------*/
class Expression {
	Stack<Element*> m_stackElementPtrs;
private:
	bool _isValidBrackets(string s);
	void _formOrder(string m_strRaw, int m_nLength, int* m_ptrOrder);
public:
	Expression(string s);
	~Expression();
	friend ostream& operator<<(ostream& out, const Expression& e);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Expression& e);

#endif /* !__EXPRESSION_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
