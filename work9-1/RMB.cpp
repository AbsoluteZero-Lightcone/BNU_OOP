/**
  ******************************************************************************
  * @file    RMB.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   RMB class
  * @encode  GB2312
  ******************************************************************************
  */

  /* Includes ------------------------------------------------------------------*/
#include "RMB.h"

/* Constructors & Deconstructor --------------------------------------------- */
RMB::RMB() :
	m_chSign('+'),
	m_nYuan(0),
	m_nJiao(0),
	m_nFen(0)
{}

RMB::RMB(int fen) { fromFen(fen); }

RMB::RMB(const RMB& source) :
	m_chSign(source.m_chSign),
	m_nYuan(source.m_nYuan),
	m_nJiao(source.m_nJiao),
	m_nFen(source.m_nFen)
{}

RMB::~RMB() {}

/* Private functions -------------------------------------------------------- */
/**
  * @brief 转化为分
  * @param None
  * @retval 分
  */
int RMB::toFen()const {
	return (m_chSign == '+' ? 1 : -1) * (m_nYuan * 100 + m_nJiao * 10 + m_nFen);
}
/**
  * @brief 从分赋值
  * @param int fen : 分
  * @retval None
  */
void RMB::fromFen(int fen) {
	if (fen >= 0)m_chSign = '+';
	else {
		m_chSign = '-';
		fen = -fen;
	}
	m_nFen = fen % 10;
	fen /= 10;
	m_nJiao = fen % 10;
	m_nYuan = fen / 10;
}

/* Exported functions ------------------------------------------------------- */
/**
  * @brief 类内重载负号
  * @param *this : 值传递待取反的值
  * @retval -*this
  */
RMB RMB::operator-() {
	return RMB(-(this->toFen()));
}

/**
  * @brief 类内重载加法运算符
  * @param *this : 加号左边的值
  * @param const RMB& n2 : 加号右边的值
  * @retval *this + n2
  */
RMB RMB::operator+(const RMB& n2) {
	return RMB((this->toFen()) + (n2.toFen()));
}

/**
  * @brief 类内重载减法运算符
  * @param *this : 被减数
  * @param const RMB& n2 : 减数
  * @retval *this - n2
  */
RMB RMB::operator-(const RMB& n2) {
	return RMB((this->toFen()) - (n2.toFen()));
}

/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const RMB& source : 待赋的值
  * @retval 无
  */
void RMB::operator=(const RMB& source) {
	m_chSign = source.m_chSign;
	m_nYuan = source.m_nYuan;
	m_nJiao = source.m_nJiao;
	m_nFen = source.m_nFen;
}

/**
  * @brief 类内重载使用分赋值的赋值运算符
  * @param int n : 分
  * @retval 无
  */
void RMB::operator=(int n) {
	fromFen(n);
}

/**
  * @brief 类内重载+=运算符
  * @param n : 分
  * @retval 返回自身引用实现链式编程
  */
RMB& RMB::operator+=(int n) {
	fromFen(toFen() + n);
	return *this;
}

/**
  * @brief 类内重载前自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
RMB& RMB::operator++() {
	fromFen(toFen() + 1);
	return *this;
}

/**
  * @brief 类内重载后自增运算符
  * @param 无
  * @retval 值返回，不支持链式调用
  */
RMB RMB::operator++(int) {
	RMB temp(*this);
	++(*this);
	return temp;
}

/**
  * @brief 重载前自减运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
RMB& operator--(RMB& n) {
	n.fromFen(n.toFen() + 1);
	return n;
}

/**
  * @brief 重载后自减运算符
  * @param 无
  * @retval 值返回，不支持链式调用
  */
RMB operator--(RMB& n, int) {
	RMB temp(n);
	--n;
	return temp;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const RMB& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const RMB& source) {
	out << "(" << source.m_chSign << source.m_nYuan << "元" << source.m_nJiao << "角" << source.m_nFen << "分)";
	return out;
}

/**
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param RMB& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
  */
istream& operator>>(istream& input, RMB& target) {
	char         t_chSign;
	unsigned int t_nYuan;
	unsigned int t_nJiao;
	unsigned int t_nFen;

	input
		>> t_chSign
		>> t_nYuan
		>> t_nJiao
		>> t_nFen;
	if (t_chSign != '+' && t_chSign != '-') {
		cerr << "Incorrect sign. Please try again:";
		input >> target;
	}
	else {
		target.m_chSign = t_chSign;
		target.m_nYuan = t_nYuan;
		target.m_nJiao = t_nJiao;
		target.m_nFen = t_nFen;
	}
	return input;
}

/**
  * @brief 重载大于运算符
  * @param const RMB& n1 : 运算符左边的值
  * @param const RMB& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const RMB& n1, const RMB& n2) {
	return n1.toFen() > n2.toFen();
}

/**
  * @brief 重载大于等于运算符
  * @param const RMB& n1 : 运算符左边的值
  * @param const RMB& n2 : 运算符右边的值
  * @retval bool, true for n1 >= n2
  */
bool operator>=(const RMB& n1, const RMB& n2) {
	return (n1 == n2) || (n1 > n2);
}

/**
  * @brief 重载小于运算符
  * @param const RMB& n1 : 运算符左边的值
  * @param const RMB& n2 : 运算符右边的值
  * @retval bool, true for n1 < n2
  */
bool operator<(const RMB& n1, const RMB& n2) {
	return !(n1 >= n2);
}

/**
  * @brief 重载小于等于运算符
  * @param const RMB& n1 : 运算符左边的值
  * @param const RMB& n2 : 运算符右边的值
  * @retval bool, true for n1 <= n2
  */
bool operator<=(const RMB& n1, const RMB& n2) {
	return !(n1 > n2);
}

/**
  * @brief 重载等于运算符
  * @param const RMB& n1 : 运算符左边的值
  * @param const RMB& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const RMB& n1, const RMB& n2) {
	if (n1.m_chSign != n2.m_chSign)return false;
	if (n1.m_nYuan != n2.m_nYuan)return false;
	if (n1.m_nJiao != n2.m_nJiao)return false;
	if (n1.m_nFen != n2.m_nFen)return false;
	return true;
}

/**
  * @brief 重载不等于运算符
  * @param const RMB& n1 : 运算符左边的值
  * @param const RMB& n2 : 运算符右边的值
  * @retval bool, true for n1 != n2
  */
bool operator!=(const RMB& n1, const RMB& n2) {
	if (n1.m_chSign == n2.m_chSign)return false;
	if (n1.m_nYuan == n2.m_nYuan)return false;
	if (n1.m_nJiao == n2.m_nJiao)return false;
	if (n1.m_nFen == n2.m_nFen)return false;
	return true;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
