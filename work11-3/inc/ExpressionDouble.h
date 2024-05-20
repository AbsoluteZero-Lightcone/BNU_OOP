/**
  ******************************************************************************
  * @file    ExpressionDouble.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-20
  * @brief   ExpressionDouble
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXPRESSIONDOUBLE_H
#define __EXPRESSIONDOUBLE_H

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
#include "ExpressionElement_Base.h"
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
	friend ostream& operator<<(ostream& out, const ExpressionDouble& e);
};
ostream& operator<<(ostream& out, const ExpressionDouble& e) {
	out << e.m_dData;
	return out;
}
/* Exported functions ------------------------------------------------------- */

#endif /* !__ExpressionDouble_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
