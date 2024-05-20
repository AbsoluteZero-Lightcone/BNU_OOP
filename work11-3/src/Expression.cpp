/**
  ******************************************************************************
  * @file    Expression.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-20
  * @brief   Expression
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "Expression.h"

/* Exported functions ------------------------------------------------------- */
/**
  * @brief ºÏ≤È¿®∫≈ «∑Ò∆•≈‰
  * @param s: ¥˝ºÏ≤È◊÷∑˚¥Æ
  * @retval bool:  «∑Ò∆•≈‰ 1:∆•≈‰ 0:≤ª∆•≈‰
  */
bool Expression::_isValidBrackets(string s) {
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

/**
  * @brief …˙≥…¿®∫≈≤„¥Œ
  * @param m_strRaw: ¥˝ºÏ≤È◊÷∑˚¥Æ
  * @param m_nLength: ◊÷∑˚¥Æ≥§∂»
  * @param m_ptrOrder: ¿®∫≈≤„¥Œ ˝◊È
  * @retval None
  */
void Expression::_formOrder(string m_strRaw, int m_nLength, int* m_ptrOrder) {
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

Expression::Expression(string s) {
	if (!_isValidBrackets(s))
		throw "Invalid Brackets.";
	while (s.length() > 0) {
		if (s[0] == ' ')s = s.substr(1);
		if (s[0] >= '0' && s[0] <= '9' || s[0] == '.') {
			ExpressionDouble* p = new ExpressionDouble();
			p->fetch(s);
			m_stackElementPtrs.push(p);
		}
		else if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') {
			ExpressionOperator* p = new ExpressionOperator();
			p->fetch(s);
			m_stackElementPtrs.push(p);
		}
		else if (s[0] == '(' || s[0] == ')') {
			ExpressionBrackets* p = new ExpressionBrackets();
			p->fetch(s);
			m_stackElementPtrs.push(p);
		}
		else throw "Invalid Expression.";
	}
}

Expression::Expression(const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionDouble))
			m_stackElementPtrs.push(new ExpressionDouble(*dynamic_cast<ExpressionDouble*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionOperator))
			m_stackElementPtrs.push(new ExpressionOperator(*dynamic_cast<ExpressionOperator*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionBrackets))
			m_stackElementPtrs.push(new ExpressionBrackets(*dynamic_cast<ExpressionBrackets*>(e.m_stackElementPtrs[i])));
		else throw "Invalid Expression.";
	}
}

Expression& Expression::operator=(const Expression& e) {
	if (this == &e)return *this;
	while (!m_stackElementPtrs.isEmpty()) {
		delete m_stackElementPtrs.pop();
	}
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionDouble))
			m_stackElementPtrs.push(new ExpressionDouble(*dynamic_cast<ExpressionDouble*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionOperator))
			m_stackElementPtrs.push(new ExpressionOperator(*dynamic_cast<ExpressionOperator*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionBrackets))
			m_stackElementPtrs.push(new ExpressionBrackets(*dynamic_cast<ExpressionBrackets*>(e.m_stackElementPtrs[i])));
		else throw "Invalid Expression.";
	}
	return *this;
}


Expression::~Expression() {
	while (!m_stackElementPtrs.isEmpty()) {
		delete m_stackElementPtrs.pop();
	}
}

ExpressionDouble Expression::Calculate(Expression e) {
	Stack<Element*> stack;
	while (!e.m_stackElementPtrs.isEmpty()) {
		Element* p = e.m_stackElementPtrs.pop();
		if (typeid(p) == typeid(ExpressionOperator)) {
			ExpressionOperator* pOperator = dynamic_cast<ExpressionOperator*>(p);
			ExpressionDouble* p2 = dynamic_cast<ExpressionDouble*>(stack.pop());
			ExpressionDouble* p1 = dynamic_cast<ExpressionDouble*>(stack.pop());
			stack.push(new ExpressionDouble(pOperator->calculate(*p1, *p2)));
		}
		else {
			stack.push(p);
		}
	}
	return *dynamic_cast<ExpressionDouble*>(stack.pop());
}


ostream& operator<<(ostream& out, const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		out << *e.m_stackElementPtrs[i];
	}
	return out;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
