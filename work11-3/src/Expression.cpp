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
			m_stackElementPtrs.back_push(p);
		}
		else if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') {
			ExpressionOperator* p = new ExpressionOperator();
			p->fetch(s);
			m_stackElementPtrs.back_push(p);
		}
		else if (s[0] == '(' || s[0] == ')') {
			ExpressionBrackets* p = new ExpressionBrackets();
			p->fetch(s);
			m_stackElementPtrs.back_push(p);
		}
		else throw "Invalid Expression.";
	}
}

Expression::Expression(const Element& e) {
	if (typeid(e) == typeid(ExpressionDouble))
		m_stackElementPtrs.back_push(new ExpressionDouble(dynamic_cast<const ExpressionDouble&>(e)));
	else if (typeid(e) == typeid(ExpressionOperator))
		m_stackElementPtrs.back_push(new ExpressionOperator(dynamic_cast<const ExpressionOperator&>(e)));
	else if (typeid(e) == typeid(ExpressionBrackets))
		m_stackElementPtrs.back_push(new ExpressionBrackets(dynamic_cast<const ExpressionBrackets&>(e)));
	else throw "Invalid Expression.";
}


Expression::Expression(const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionDouble))
			m_stackElementPtrs.back_push(new ExpressionDouble(*dynamic_cast<ExpressionDouble*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionOperator))
			m_stackElementPtrs.back_push(new ExpressionOperator(*dynamic_cast<ExpressionOperator*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionBrackets))
			m_stackElementPtrs.back_push(new ExpressionBrackets(*dynamic_cast<ExpressionBrackets*>(e.m_stackElementPtrs[i])));
		else throw "Invalid Expression.";
	}
}

Expression& Expression::operator=(const Expression& e) {
	if (this == &e)return *this;
	while (!m_stackElementPtrs.empty()) {
		delete m_stackElementPtrs.back_pop();
	}
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionDouble))
			m_stackElementPtrs.back_push(new ExpressionDouble(*dynamic_cast<ExpressionDouble*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionOperator))
			m_stackElementPtrs.back_push(new ExpressionOperator(*dynamic_cast<ExpressionOperator*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionBrackets))
			m_stackElementPtrs.back_push(new ExpressionBrackets(*dynamic_cast<ExpressionBrackets*>(e.m_stackElementPtrs[i])));
		else throw "Invalid Expression.";
	}
	return *this;
}


Expression::~Expression() {
	while (!m_stackElementPtrs.empty()) {
		delete m_stackElementPtrs.back_pop();
	}
}


Element& Expression::operator[](int t_nIndex)const { return *m_stackElementPtrs[t_nIndex]; }
Element& Expression::at(int t_nIndex)const { return *m_stackElementPtrs[t_nIndex]; }
Element& Expression::front()const { return *m_stackElementPtrs[0]; }
Element& Expression::back()const { return *m_stackElementPtrs[m_stackElementPtrs.size() - 1]; }

Element& Expression::top()const { return *m_stackElementPtrs[m_stackElementPtrs.size() - 1]; }
Element& Expression::bottom()const { return *m_stackElementPtrs[0]; }
int Expression::size()const { return m_stackElementPtrs.size(); }
bool Expression::empty()const { return m_stackElementPtrs.empty(); }
void Expression::insert(int t_nIndex, Element& t_data) { m_stackElementPtrs.insert(t_nIndex, &t_data); }
void Expression::remove(int t_nIndex) { m_stackElementPtrs.remove(t_nIndex); }
void Expression::pop_back() { delete m_stackElementPtrs.back_pop(); }
void Expression::push_back(Element& e) { m_stackElementPtrs.back_push(&e); }


//  π”√µ›πÈ∑Ω∑®º∆À„±Ì¥Ô Ω
ExpressionDouble Expression::Calculate(Expression e) {
	if (e.m_stackElementPtrs.size() == 1) {
		if (typeid(e.m_stackElementPtrs[0]) == typeid(ExpressionDouble))
			return *dynamic_cast<ExpressionDouble*>(e.m_stackElementPtrs[0]);
		else throw "Invalid Expression.";
	}
	else {
		int i = 0;
		while (typeid(e.m_stackElementPtrs[i]) != typeid(ExpressionOperator))i++;
		ExpressionDouble a = Calculate(*(e.m_stackElementPtrs[i - 2]));
		ExpressionDouble b = Calculate(*e.m_stackElementPtrs[i - 1]);
		ExpressionOperator* p = dynamic_cast<ExpressionOperator*>(e.m_stackElementPtrs[i]);
		ExpressionDouble c = p->operate(a, b);
		e.m_stackElementPtrs.remove(i - 2);
		e.m_stackElementPtrs.remove(i - 2);
		e.m_stackElementPtrs.remove(i - 2);
		e.m_stackElementPtrs.insert(i - 2, &c);
		return Calculate(e);
	}
}


ostream& operator<<(ostream& out, const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		out << *e.m_stackElementPtrs[i];
	}
	return out;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
