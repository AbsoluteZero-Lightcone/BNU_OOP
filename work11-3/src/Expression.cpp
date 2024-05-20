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
  * @brief 检查括号是否匹配
  * @param s: 待检查字符串
  * @retval bool: 是否匹配 1:匹配 0:不匹配
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
  * @brief 生成括号层次
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

/**
  * @brief 生成括号层次
  * @retval None
  */
void Expression::_formOrder(Expression e, int* m_ptrOrder) {
	int cur = 0;
	for (int i = 0; i < e.size(); i++) {
		if (typeid(e[i]) == typeid(ExpressionBrackets)) {
			ExpressionBrackets eb = dynamic_cast<ExpressionBrackets&>(e[i]);
			if (eb.getOperator() == '(') {
				cur++;
				m_ptrOrder[i] = -1;
			}
			else if (eb.getOperator() == ')') {
				cur--;
				m_ptrOrder[i] = -1;
			}
			else {
				m_ptrOrder[i] = cur;
			}
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
			m_stackElementPtrs.push_back(p);
		}
		else if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') {
			ExpressionOperator* p = new ExpressionOperator();
			p->fetch(s);
			m_stackElementPtrs.push_back(p);
		}
		else if (s[0] == '(' || s[0] == ')') {
			ExpressionBrackets* p = new ExpressionBrackets();
			p->fetch(s);
			m_stackElementPtrs.push_back(p);
		}
		else throw "Invalid Expression.";
	}
}

Expression::Expression(Element& e) { push_back(e); }

Expression::Expression(const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		push_back(e[i]);
	}
}

/**
  * @brief 截取表达式
  */
Expression::Expression(const Expression& e, int start, int end) {
	for (int i = start; i < end; i++) {
		push_back(e[i]);
	}
}

Expression& Expression::operator=(const Expression& e) {
	if (this == &e)return *this;
	while (!m_stackElementPtrs.empty()) {
		delete m_stackElementPtrs.pop_back();
	}
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionDouble))
			m_stackElementPtrs.push_back(new ExpressionDouble(*dynamic_cast<ExpressionDouble*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionOperator))
			m_stackElementPtrs.push_back(new ExpressionOperator(*dynamic_cast<ExpressionOperator*>(e.m_stackElementPtrs[i])));
		else if (typeid(e.m_stackElementPtrs[i]) == typeid(ExpressionBrackets))
			m_stackElementPtrs.push_back(new ExpressionBrackets(*dynamic_cast<ExpressionBrackets*>(e.m_stackElementPtrs[i])));
		else throw "Invalid Expression.";
	}
	return *this;
}


Expression::~Expression() {
	while (!m_stackElementPtrs.empty()) {
		delete m_stackElementPtrs.pop_back();
	}
}


Element& Expression::operator[](int t_nIndex)const { return *m_stackElementPtrs[t_nIndex]; }
Element& Expression::at(int t_nIndex)const { return *m_stackElementPtrs.at(t_nIndex); }
Element& Expression::front()const { return *m_stackElementPtrs[0]; }
Element& Expression::back()const { return *m_stackElementPtrs[m_stackElementPtrs.size() - 1]; }
Element& Expression::top()const { return *m_stackElementPtrs[m_stackElementPtrs.size() - 1]; }
Element& Expression::bottom()const { return *m_stackElementPtrs[0]; }
int Expression::size()const { return m_stackElementPtrs.size(); }
bool Expression::empty()const { return m_stackElementPtrs.empty(); }

// 注意下面4个都得是深拷贝
void Expression::insert(int t_nIndex, Element& e) {
	Element* p = nullptr;
	if (typeid(e) == typeid(ExpressionDouble))
		p = new ExpressionDouble(dynamic_cast<ExpressionDouble&>(e));
	else if (typeid(e) == typeid(ExpressionOperator))
		p = new ExpressionOperator(dynamic_cast<ExpressionOperator&>(e));
	else if (typeid(e) == typeid(ExpressionBrackets))
		p = new ExpressionBrackets(dynamic_cast<ExpressionBrackets&>(e));
	else throw "Invalid Expression.";
	m_stackElementPtrs.insert(t_nIndex, p);
}
void Expression::remove(int t_nIndex) {
	delete m_stackElementPtrs[t_nIndex];
	m_stackElementPtrs.remove(t_nIndex);
}
void Expression::pop_back() {
	delete m_stackElementPtrs.pop_back();
}
void Expression::push_back(Element& e) {
	Element* p = nullptr;
	if (typeid(e) == typeid(ExpressionDouble))
		p = new ExpressionDouble(dynamic_cast<ExpressionDouble&>(e));
	else if (typeid(e) == typeid(ExpressionOperator))
		p = new ExpressionOperator(dynamic_cast<ExpressionOperator&>(e));
	else if (typeid(e) == typeid(ExpressionBrackets))
		p = new ExpressionBrackets(dynamic_cast<ExpressionBrackets&>(e));
	else throw "Invalid Expression.";
	m_stackElementPtrs.push_back(p);
}


// 使用递归方法计算表达式
ExpressionDouble Expression::Calculate(Expression e) {
	cout << "sub-tree: " << e << endl;
	if (e.size() == 1) {
		if (typeid(e[0]) == typeid(ExpressionDouble))
			return dynamic_cast<ExpressionDouble&>(e[0]);
		else throw "Invalid Expression.";
	}
	int n = 0;// 找带括号的表达式中优先级最低的运算符，作为分割点
	int min = INT32_MAX;
	int* order = new int[e.size()];
	//cout << "前" << e.size() << endl;
	//cout << e.at(0) << endl;
	_formOrder(e, order);
	//cout << "后" << e.size() << endl;
	//cout << e.at(0) << endl;
	cout << "Order: ";
	for (int i = 0; i < e.size(); i++) {
		cout << order[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < e.size(); i++) {
		//cout << e[i] << endl;
		//cout << typeid(e[i]).name() << endl;
		if (typeid(e[i]) == typeid(ExpressionOperator)) {
			ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[i]);
			if (op.getPriority() < min && order[i] == 0) { // 在最外层的运算符中找优先级最低的
				min = op.getPriority();
				n = i;
			}
		}
	}
	delete[] order;

	cout << "operator: " << e[n] << endl;

	ExpressionDouble a = Calculate(Expression(e, 0, n));
	ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[n]);
	ExpressionDouble b = Calculate(Expression(e, n + 1, e.size()));
	return op.operate(a, b);
}

ExpressionDouble Expression::calculate() { return Calculate(*this); }

ExpressionDouble Expression::eval(string s) { return Calculate(Expression(s)); }

ostream& operator<<(ostream& out, const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		out << *e.m_stackElementPtrs[i];
	}
	return out;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
