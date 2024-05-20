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

/* Class ---------------------------------------------------------------------*/
class Expression {
	Stack<Element*> m_stackElementPtrs;
private:
	bool _isValidBrackets(string s) {
		int cur = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(')
				cur++;
			else if (s[i] == ')')
				cur--;
			if (cur < 0)return false;
		}
		return !cur;
	}
	void _formOrder(string m_strRaw, int m_nLength, int* m_ptrOrder) {
		int cur = 0;
		for (int i = 0; i < m_nLength; i++) {
			if (m_strRaw[i] == '(') {
				cur++;
				m_ptrOrder[i] = -1;
			}
			else if (m_strRaw[i] == ')') {
				cur--;
				m_ptrOrder[i] = -1;
			}
			else {
				m_ptrOrder[i] = cur;
			}
		}
	}
public:
	Expression(string s) {
		if (!_isValidBrackets(s))
			throw "Invalid Brackets.";
		while (s.length() > 0) {
			if (s[0] == ' ')s = s.substr(1);
			if (s[0] >= '0' && s[0] <= '9' || s[0] == '.') {
				ExpressionDouble* p = new ExpressionDouble();
				p->fetch(s);
				m_stackElementPtrs.push(p);
			}
			else if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '(' || s[0] == ')') {
				ExpressionOperator* p = new ExpressionOperator();
				p->fetch(s);
				m_stackElementPtrs.push(p);
			}
			else throw "Invalid Expression.";
		}
	}
	~Expression() {
		while (!m_stackElementPtrs.isEmpty()) {
			delete m_stackElementPtrs.pop();
		}
	}
	friend ostream& operator<<(ostream& out, const Expression& e);
};

ostream& operator<<(ostream& out, const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		out << *e.m_stackElementPtrs[i];
	}
	return out;
}
/* Exported functions ------------------------------------------------------- */

#endif /* !__EXPRESSION_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
