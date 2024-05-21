/**
  ******************************************************************************
  * @file    Expression.cpp
  * @author  Zhang Yifa 202311998186
  * @version V2.5.4
  * @date    2024-05-20
  * @brief   Expression
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ----------------------------------------------------------------- */
#include "Expression.h"

/* Interfaces --------------------------------------------------------------- */
Expression::Expression(string s) { fetch(s); }
Expression::Expression(Element& e) { push_back(e); }
Expression::Expression(const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++)
		push_back(e[i]);
}
Expression::Expression(const Expression& e, int start, int end) {
	for (int i = start; i < end; i++)
		push_back(e[i]);
}
Expression& Expression::operator=(const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++)
		push_back(e[i]);
	return *this;
}
Expression& Expression::operator=(string s) {
	fetch(s);
	return *this;
}
Expression::~Expression() {
	clear();
}

Element& Expression::operator[](int t_nIndex)const { return *m_stackElementPtrs[t_nIndex]; }
Element& Expression::at(int t_nIndex)const { return *m_stackElementPtrs.at(t_nIndex); }
Element& Expression::front()const { return *m_stackElementPtrs[0]; }
Element& Expression::back()const { return *m_stackElementPtrs[m_stackElementPtrs.size() - 1]; }
Element& Expression::top()const { return *m_stackElementPtrs[m_stackElementPtrs.size() - 1]; }
Element& Expression::bottom()const { return *m_stackElementPtrs[0]; }
int Expression::size()const { return m_stackElementPtrs.size(); }
bool Expression::empty()const { return m_stackElementPtrs.empty(); }

void Expression::append(const Expression& e) {
	for (int i = 0; i < e.size(); i++)
		push_back(e[i]);
}

/* Exported functions ------------------------------------------------------- */
ExpressionDouble Expression::calculate() { return Calculate(*this); }
ExpressionDouble Expression::eval(string s) { return Calculate(Expression(s)); }
ostream& operator<<(ostream& out, const Expression& e) {
	for (int i = 0; i < e.m_stackElementPtrs.size(); i++) {
		if (i)out << " ";
		out << *e.m_stackElementPtrs[i];
	}
	return out;
}
istream& operator>>(istream& in, Expression& e) {
	string s;
	in >> s;
	e = Expression(s);
	return in;
}

Expression operator+(const Expression& e1, const Expression& e2) {
	Expression e;
	e.append(e1);
	e.push_back(ExpressionOperator('+'));
	e.append(e2);
	return e;
}
Expression operator-(const Expression& e1, const Expression& e2) {
	Expression e;
	e.append(e1);
	e.push_back(ExpressionOperator('-'));
	e.append(e2);
	return e;
}
Expression operator*(const Expression& e1, const Expression& e2) {
	Expression e;
	e.append(e1);
	e.push_back(ExpressionOperator('*'));
	e.append(e2);
	return e;
}
Expression operator/(const Expression& e1, const Expression& e2) {
	Expression e;
	e.append(e1);
	e.push_back(ExpressionOperator('/'));
	e.append(e2);
	return e;
}
Expression operator%(const Expression& e1, const Expression& e2) {
	Expression e;
	e.append(e1);
	e.push_back(ExpressionOperator('%'));
	e.append(e2);
	return e;
}
Expression operator^(const Expression& e1, const Expression& e2) {
	Expression e;
	e.append(e1);
	e.push_back(ExpressionOperator('^'));
	e.append(e2);
	return e;
}
Expression operator-(const Expression& e) {
	Expression ne;
	ne.push_back(ExpressionOperator('-'));
	ne.append(e);
	return ne;
}
Expression operator+(const Expression& e) {
	return e;
}

/* Memory Handling Function ------------------------------------------------- */
Expression::Expression() { m_stackElementPtrs.push_back(new ExpressionDouble()); }
void Expression::insert(int t_nIndex, const Element& e) {
	Element* p = nullptr;
	if (typeid(e) == typeid(ExpressionDouble))
		p = new ExpressionDouble(dynamic_cast<ExpressionDouble&>(const_cast<Element&>(e)));
	else if (typeid(e) == typeid(ExpressionOperator))
		p = new ExpressionOperator(dynamic_cast<ExpressionOperator&>(const_cast<Element&>(e)));
	else if (typeid(e) == typeid(ExpressionBrackets))
		p = new ExpressionBrackets(dynamic_cast<ExpressionBrackets&>(const_cast<Element&>(e)));
	else throw "Invalid Object.";
	m_stackElementPtrs.insert(t_nIndex, p);
}
void Expression::remove(int t_nIndex) {
	delete m_stackElementPtrs[t_nIndex];
	m_stackElementPtrs.remove(t_nIndex);
}
void Expression::pop_back() {
	delete m_stackElementPtrs.pop_back();
}
void Expression::push_back(const Element& e) {
	Element* p = nullptr;
	if (typeid(e) == typeid(ExpressionDouble))
		p = new ExpressionDouble(dynamic_cast<ExpressionDouble&>(const_cast<Element&>(e)));
	else if (typeid(e) == typeid(ExpressionOperator))
		p = new ExpressionOperator(dynamic_cast<ExpressionOperator&>(const_cast<Element&>(e)));
	else if (typeid(e) == typeid(ExpressionBrackets))
		p = new ExpressionBrackets(dynamic_cast<ExpressionBrackets&>(const_cast<Element&>(e)));
	else throw "Invalid Object.";
	m_stackElementPtrs.push_back(p);
}
void Expression::clear() {
	while (!m_stackElementPtrs.empty()) {
		delete m_stackElementPtrs.pop_back();
	}
}

/* Private Functions -------------------------------------------------------- */
/**
  * @brief ��������Ƿ�ƥ��
  * @param s: ������ַ���
  * @retval bool: �Ƿ�ƥ�� 1:ƥ�� 0:��ƥ��
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
  * @brief �������Ų�Σ�Խ�������Ų��Խ�ߣ����ź����ƽ��
  * @retval None
  */
void Expression::_formOrder(Expression e, int* hierarchy) {
	int cur = 0;
	for (int i = 0; i < e.size(); i++) {
		if (typeid(e[i]) == typeid(ExpressionBrackets)) {
			ExpressionBrackets eb = dynamic_cast<ExpressionBrackets&>(e[i]);
			if (eb.getOperator() == '(') {
				hierarchy[i] = cur;
				cur++;
			}
			else if (eb.getOperator() == ')') {
				cur--;
				hierarchy[i] = cur;
			}
			else {
				hierarchy[i] = cur;
			}
		}
		else {
			hierarchy[i] = cur;
		}
	}
}

/**
  * @brief �ж������Ƿ����
  * @retval Bool: �Ƿ�ƥ�� 1:ƥ�� 0:��ƥ��
  */
bool Expression::_isPaired(const Expression& e, int l, int r) {
	if (typeid(e[l]) != typeid(ExpressionBrackets) || typeid(e[r]) != typeid(ExpressionBrackets))
		return false;
	ExpressionBrackets lb = dynamic_cast<ExpressionBrackets&>(e[l]);
	ExpressionBrackets rb = dynamic_cast<ExpressionBrackets&>(e[r]);
	if (lb.getOperator() != '(' || rb.getOperator() != ')')return false;

	int* order = new int[e.size()];
	_formOrder(e, order);
	for (int i = l + 1; i < r; i++)
		if (order[i] == order[l]) {
			delete[] order;
			return false;
		}
	delete[] order;
	return true;
}

/**
  * @brief �ж������Ƿ���ԣ������ظ��������Ų������
  * @retval Bool: �Ƿ�ƥ�� 1:ƥ�� 0:��ƥ��
  */
bool Expression::_isPaired(const Expression& e, int* hierarchy, int l, int r) {
	if (typeid(e[l]) != typeid(ExpressionBrackets) || typeid(e[r]) != typeid(ExpressionBrackets))
		return false;
	ExpressionBrackets lb = dynamic_cast<ExpressionBrackets&>(e[l]);
	ExpressionBrackets rb = dynamic_cast<ExpressionBrackets&>(e[r]);
	if (lb.getOperator() != '(' || rb.getOperator() != ')')return false;

	if (hierarchy[l] != hierarchy[r])return false;
	for (int i = l + 1; i < r; i++)
		if (hierarchy[i] == hierarchy[l])return false;
	return true;
}

/* Major Functions ---------------------------------------------------------- */
/**
  * @brief ���ַ�������ȡ���ʽ
  */
void Expression::fetch(string s) {
	if (!_isValidBrackets(s))
		throw "Invalid Brackets: ���Ų����";
	clear();
	while (s.length() > 0) {
		if (s[0] == ' ')s = s.substr(1);
		if (s[0] >= '0' && s[0] <= '9' || s[0] == '.') {
			ExpressionDouble* p = new ExpressionDouble();
			p->fetch(s);
			m_stackElementPtrs.push_back(p);
		}
		else if (
			s[0] == '+' ||
			s[0] == '-' ||
			s[0] == '*' ||
			s[0] == '/' ||
			s[0] == '%' ||
			s[0] == '^'
			) {
			ExpressionOperator* p = new ExpressionOperator();
			p->fetch(s);
			m_stackElementPtrs.push_back(p);
		}
		else if (s[0] == '(' || s[0] == ')') {
			ExpressionBrackets* p = new ExpressionBrackets();
			p->fetch(s);
			m_stackElementPtrs.push_back(p);
		}
		else throw "Invalid Expression: ������Ч�ַ�";
	}
}

/**
  * @brief ʹ�õݹ鷽��������ʽ
  */
ExpressionDouble Expression::Calculate(Expression e) {
	if (e.size() == 0)throw "Invalid Expression: ���ڿ�����";// ��������Ų����Ŀձ��ʽ
	if (e.size() == 1) {
		if (typeid(e[0]) == typeid(ExpressionDouble))
			return dynamic_cast<ExpressionDouble&>(e[0]);
		else throw "Invalid Expression: ���ڹ����ķ���";
	}
	if (typeid(e[0]) == typeid(ExpressionOperator)) { // ����ͷ�������
		ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[0]);
		if (op.getPriority() == 1) { // ����ͷ�ļӼ��Ŵ���Ϊ������
			ExpressionDouble a = ExpressionDouble(0);
			ExpressionDouble b = Calculate(Expression(e, 1, e.size()));
			return op.operate(a, b);
		}
		else throw "Invalid Expression: ǰ׺ֻ����������";
	}

	int* hierarchy = new int[e.size()];
	_formOrder(e, hierarchy);
	if (_isPaired(e, hierarchy, 0, e.size() - 1)) { // ȥ���������ţ����������¶�������
		return Calculate(Expression(e, 1, e.size() - 1));
	}

	int n = -1;// �����ʽ�����ȼ���͵��������Ϊ�ָ��
	int min = INT32_MAX;
	for (int i = 0; i < e.size(); i++) { // �����ң�ƽ��������������ұߵ������
		if (typeid(e[i]) == typeid(ExpressionOperator)) { // ɸѡ���������Ԫ��
			ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[i]);
			if (hierarchy[i] == 0 && op.getPriority() < min) { // ������������ȼ���͵������
				min = op.getPriority();
				n = i;
			}
		}
	}
	if (n == -1)throw "Invalid Expression: ȱ�������";

	delete[] hierarchy;

	if (n <= 0 || n + 1 >= e.size())throw "Invalid Expression: ��������Ĳ�������";
	ExpressionDouble a = Calculate(Expression(e, 0, n));
	ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[n]);
	ExpressionDouble b = Calculate(Expression(e, n + 1, e.size()));
	return op.operate(a, b);
}

#define prefix(s2,n){for(int i=0;i<n;i++)cout<<"      ";cout<<s2;}

/**
  * @brief ʹ�õݹ鷽��������ʽ
  */
ExpressionDouble Expression::Process(Expression e, int depth) {
	if (e.size() == 0)throw "Invalid Expression: ���ڿ�����";// ��������Ų����Ŀձ��ʽ
	if (e.size() == 1) {
		if (typeid(e[0]) == typeid(ExpressionDouble)) {
			prefix( "| >>> ", depth);	cout << e << endl;
			return dynamic_cast<ExpressionDouble&>(e[0]);
		}
		else throw "Invalid Expression: ���ڹ����ķ���";
	}
	if (typeid(e[0]) == typeid(ExpressionOperator)) { // ����ͷ�������
		ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[0]);
		if (op.getPriority() == 1) { // ����ͷ�ļӼ��Ŵ���Ϊ������
			ExpressionDouble a = ExpressionDouble(0);
			ExpressionDouble b = Calculate(Expression(e, 1, e.size()));
			prefix( "| >>> ", depth);	cout << e << endl;
			return op.operate(a, b);
		}
		else throw "Invalid Expression: ǰ׺ֻ����������";
	}

	int* hierarchy = new int[e.size()];
	_formOrder(e, hierarchy);
	if (_isPaired(e, hierarchy, 0, e.size() - 1)) { // ȥ���������ţ����������¶�������
		return Process(Expression(e, 1, e.size() - 1),depth);// ����ӡȥ���ŵĹ���
	}

	int n = -1;// �����ʽ�����ȼ���͵��������Ϊ�ָ��
	int min = INT32_MAX;
	for (int i = 0; i < e.size(); i++) { // �����ң�ƽ��������������ұߵ������
		if (typeid(e[i]) == typeid(ExpressionOperator)) { // ɸѡ���������Ԫ��
			ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[i]);
			if (hierarchy[i] == 0 && op.getPriority() < min) { // ������������ȼ���͵������
				min = op.getPriority();
				n = i;
			}
		}
	}
	if (n == -1)throw "Invalid Expression: �Ҳ��������";

	//prefix( "| >>> ��", depth);	cout << e << endl;
	//prefix( "", depth); cout << "      ��hierarchy: "; for (int i = 0; i < e.size(); i++)cout << hierarchy[i] << " "; cout << endl;
	prefix( "| >>> ", depth);	cout << e << "\t\t(hierarchy: "; for (int i = 0; i < e.size(); i++)cout << hierarchy[i] << " "; cout <<")" << endl;
	prefix( "", depth + 1); cout << "operator" << e[n] << endl;
	
	delete[] hierarchy;

	if (n <= 0 || n + 1 >= e.size())throw "Invalid Expression: ��������Ĳ�������";
	ExpressionDouble a = Process(Expression(e, 0, n), depth + 1);
	ExpressionOperator op = dynamic_cast<ExpressionOperator&>(e[n]);
	ExpressionDouble b = Process(Expression(e, n + 1, e.size()), depth + 1);
	return op.operate(a, b);
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
