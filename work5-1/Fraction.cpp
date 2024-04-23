/**
  ******************************************************************************
  * @file    Fraction.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Fraction class
  * @encode  GB2312
  ******************************************************************************
  */

#include "Fraction.h"

/* Constructors & Deconstructor --------------------------------------------- */
Fraction::Fraction(const Fraction& n) {
	m_nNum = n.m_nNum;
	m_nDen = n.m_nDen;
}

Fraction::Fraction(int n, int d) {
	if (d == 0) {
		cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
			<< "分母不能为0"
			<< endl;
		abort();
	}
	m_nNum = n;
	m_nDen = d;
	Standardize();
}
Fraction::~Fraction() {}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Fraction& source : 待赋的值
  * @retval 无
  */
void Fraction::operator=(const Fraction& source) {
	m_nNum = source.m_nNum;
	m_nDen = source.m_nDen;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Fraction& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Fraction& source) {
	// todo
	return out;
}

/**
  * @brief 重载等于运算符
  * @param const Fraction& n1 : 运算符左边的值
  * @param const Fraction& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Fraction& n1, const Fraction& n2) {
	if (n1.m_nNum != n2.m_nNum)return false;
	if (n1.m_nDen != n2.m_nDen)return false;
	return false;
}
/**
  * @brief 约分
  * @param None
  * @retval None
  */
void Fraction::Standardize() {
	if (m_nNum == 0)m_nDen = 1;
	else {
		int gcd = GCD(m_nNum, m_nDen);
		m_nNum /= gcd;
		m_nDen /= gcd;
	}
}


// 规定动作
void Fraction::Show() {
	cout << m_nNum << "/" << m_nDen;
}

Fraction operator+(const Fraction& n1, const Fraction& n2) {
	Fraction f;
	f.m_nDen = n1.m_nDen * n2.m_nDen;
	f.m_nNum = n1.m_nNum * n2.m_nDen + n1.m_nDen * n2.m_nNum;
	f.Standardize();
	return f;
}

/**
  * @brief 辗转相除法求出两数的最大公因数，可接受负数，其中任一不能为零
  * @param a, b : 非零整数
  * @retval 最大公因数
  */
int GCD(int a, int b) {
	if (a == 0 || b == 0) {
		cerr << "Error: in file \"" << __FILE__ << "\", Line " << __LINE__ << ": "
			<< "参与最大公因数计算的数值不能为0"
			<< endl;
		abort();
	}
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	if (a > b)swap(a, b);// 保证  n1 < n2
	int c = a % b;
	while (1) {
		if (b % c == 0)return c;
		// GCD 步骤 滚动数组： 
		// 变量	a   b    c
		//		a , b , a%b , a%(a%b) , ... , (n-2)%(n-1) , ... , GCD , 0
		// 数组向 <-- 方向移动
		a = b;
		b = c;
		c = a % b;
	}
}
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
