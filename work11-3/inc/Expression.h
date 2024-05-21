/**
  ******************************************************************************
  * @file    Expression.h
  * @author  Zhang Yifa 202311998186
  * @version V2.0.0
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
	static void _formOrder(class Expression e, int* hierarchy);
	static bool _isPaired(const Expression& e, int l,int r);
	static bool _isPaired(const Expression& e,int* hierarchy, int l,int r);
public:
	Expression();
	Expression(string s);
	Expression(Element& e);
	Expression(const Expression& e);
	Expression(const Expression& e, int start, int end);
	Expression& operator=(const Expression& e);
	Expression& operator=(string s);
	~Expression();

	void fetch(string s);

	Element& operator[](int t_nIndex)const;
	Element& at(int t_nIndex)const;
	Element& front()const;
	Element& back()const;
	Element& top()const;
	Element& bottom()const;
	int size()const;
	bool empty()const;

	void insert(int t_nIndex, const Element& t_data);
	void remove(int t_nIndex);
	void pop_back();
	void push_back(const Element& e);
	void clear();

	void append(const Expression& e);

	static ExpressionDouble Calculate(Expression e);
	static ExpressionDouble Process(Expression e,int depth = 0);
	ExpressionDouble calculate();
	static ExpressionDouble eval(string s);

	friend ostream& operator<<(ostream& out, const Expression& e);
	friend istream& operator>>(istream& in, Expression& e);
	friend Expression operator+(const Expression& e1, const Expression& e2);
	friend Expression operator-(const Expression& e1, const Expression& e2);
	friend Expression operator*(const Expression& e1, const Expression& e2);
	friend Expression operator/(const Expression& e1, const Expression& e2);
	friend Expression operator%(const Expression& e1, const Expression& e2);
	friend Expression operator^(const Expression& e1, const Expression& e2);
	friend Expression operator-(const Expression& e);
	friend Expression operator+(const Expression& e);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Expression& e);
istream& operator>>(istream& in, Expression& e);

Expression operator+(const Expression& e1, const Expression& e2);
Expression operator-(const Expression& e1, const Expression& e2);
Expression operator*(const Expression& e1, const Expression& e2);
Expression operator/(const Expression& e1, const Expression& e2);
Expression operator%(const Expression& e1, const Expression& e2);
Expression operator^(const Expression& e1, const Expression& e2);
Expression operator-(const Expression& e);
Expression operator+(const Expression& e);
#endif /* !__EXPRESSION_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
