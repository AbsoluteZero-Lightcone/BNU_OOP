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
#include "ExpressionBrackets.h"

/* Class ---------------------------------------------------------------------*/
class Expression {
	Stack<Element*> m_stackElementPtrs;
private:
	static bool _isValidBrackets(string s);
	static void _formOrder(string m_strRaw, int m_nLength, int* m_ptrOrder);
	static void _formOrder(class Expression e, int* m_ptrOrder);
public:
	Expression(string s);
	Expression(Element& e);
	Expression(const Expression& e);
	Expression(const Expression& e, int start, int end);
	Expression& operator=(const Expression& e);
	~Expression();

	// 元素的对外Getter接口全部传引用
	Element& operator[](int t_nIndex)const;
	Element& at(int t_nIndex)const;
	Element& front()const;
	Element& back()const;
	Element& top()const;
	Element& bottom()const;
	int size()const;
	bool empty()const;

	// 操作表达式接口，解决内存泄漏问题
	void insert(int t_nIndex, Element& t_data);
	void remove(int t_nIndex);
	void pop_back();
	void push_back(Element& e);

	static ExpressionDouble Calculate(Expression e);
	//ExpressionDouble calculate();
	//static ExpressionDouble eval(string s);

	friend ostream& operator<<(ostream& out, const Expression& e);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Expression& e);

#endif /* !__EXPRESSION_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
