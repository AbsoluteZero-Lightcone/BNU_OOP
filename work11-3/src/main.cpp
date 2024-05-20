/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-16
  * @brief   Entrance Function
  * @encode  GB2312
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;
#include "Stack.h"
#include <cassert>
class ExpressionElement_Base {
	virtual void fetch(string& s) = 0;
	virtual ostream& operator<<(ostream& out) = 0;
};
using Element = ExpressionElement_Base;

class ExpressionDouble :public ExpressionElement_Base {
	double m_dData;
public:
	void fetch(string& s) {
		assert(s.length() > 0);
		m_dData = 0;
		int i = 0;
		while (s[i] >= '0' && s[i] <= '9') { // 整数部分
			m_dData = m_dData * 10 + (s[i] - '0');
			i++;
			if (i >= s.length())break;
		}
		if (s[i] == '.') { // 小数部分
			// 允许没有整数部分 .123 == 0.123
			// 也允许没有小数部分 123. == 123
			i++;
			double weight = 0.1; // 位权
			while (s[i] >= '0' && s[i] <= '9') {
				m_dData += weight * (s[i] - '0');
				weight *= 0.1;
				i++;
				if (i >= s.length())break;
			}
		}
		s = s.substr(i);
	}
	ostream& operator<<(ostream& out) {
		out << m_dData;
		return out;
	}
};
class ExpressionOperator :public ExpressionElement_Base {
	char m_cOperator;
public:
	void fetch(string& s) {
		assert(s.length() > 0);
		assert(
			s[0] == '+' ||
			s[0] == '-' ||
			s[0] == '*' ||
			s[0] == '/' ||
			s[0] == '(' ||
			s[0] == ')'
		);
		m_cOperator = s[0];
		s = s.substr(1);
	}
	ostream& operator<<(ostream& out) {
		out << m_cOperator;
		return out;
	}
};


class Experssion {
	Stack<Element*> m_stackElementPtrs;

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
public:
	Experssion(string s) {
		if(!_isValidBrackets(s))throw "Invalid Brackets.";
		while (s.length() > 0) {
			if (s[0] == ' ')s = s.substr(1);
			if (s[0] >= '0' && s[0] <= '9' || s[0] == '.') {
				ExpressionDouble* p = new ExpressionDouble();
				p->fetch(s);
				m_stackElementPtrs.push(p);
			}
			else if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '(' || s[0] == ')'){
				ExpressionOperator* p = new ExpressionOperator();
				p->fetch(s);
				m_stackElementPtrs.push(p);
			}
			else {
				throw "Invalid Expression.";
			}
		}
	}
};

int main() {

	return 0;
}


class Expression {
private:
	string m_strRaw;
	int m_nLength;
	int* m_ptrOrder;
	double m_dValue;

	bool _isValidCharacters(string s) {
		for (int i = 0; i < s.length(); i++)
			if (
				s[i] != '+' &&
				s[i] != '-' &&
				s[i] != '*' &&
				s[i] != '/' &&
				s[i] != '.' &&
				s[i] != '(' &&
				s[i] != ')' &&
				s[i] < '0' &&
				s[i] > '9'
				)
				return false;
	}
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

	void _formOrder() {
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
	void _Calculate() {

	}
public:
	Expression(string s) {
		if (_isValidCharacters(s))throw "Valid Characters.";
		if (_isValidBrackets(s))throw "Incorrect Brackets.";
		m_strRaw = s;
		m_nLength = s.length();
		m_ptrOrder = new int[m_nLength];

	}
};


template<class T>
void printArray(T* arr, unsigned N) {
	cout << "{";
	for (int i = 0; i < N; i++) {
		if (i)cout << ",";
		cout << arr[i];
	}
	cout << "}";
	cout << endl;
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
