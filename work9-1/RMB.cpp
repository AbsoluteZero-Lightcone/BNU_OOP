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
	m_nYuan(0),
	m_nJiao(0),
	m_nFen(0)
{}

RMB::RMB(const RMB& source) :
	m_chSign(source.m_chSign),
	m_nYuan(source.m_nYuan),
	m_nJiao(source.m_nJiao),
	m_nFen(source.m_nFen)
{}

RMB::~RMB() {}

/* Private functions -------------------------------------------------------- */
/* Exported functions ------------------------------------------------------- */
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
  * @brief 类内重载使用整数赋值的赋值运算符
  * @param int n : 待赋的值
  * @retval 无
  */
void RMB::operator=(int n) {
	// todo
}

/**
  * @brief 类内重载+=运算符
  * @param n : 待加的值
  * @retval 返回自身引用实现链式编程
  */
RMB& RMB::operator+=(int n) {
	// todo
	return *this;
}

/**
  * @brief 类内重载前自增运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
RMB& RMB::operator++() {
	// todo
	return *this;
}

/**
  * @brief 类内重载前自减运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
RMB& RMB::operator--() {
	// todo
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
  * @brief 类内重载后自减运算符
  * @param 无
  * @retval 值返回，不支持链式调用
  */
RMB RMB::operator--(int) {
	RMB temp(*this);
	--(*this);
	return temp;
}

/**
  * @brief 类内重载取反运算符
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
RMB& RMB::operator!() {
	// todo
	return *this;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const RMB& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const RMB& source) {
	// todo
	return out;
}

/**
  * @brief 重载标准输入流 >>运算符
  * @param istream& input : 标准输出流对象
  * @param RMB& target : 接受输入数据的对象
  * @retval istream& 实现链式编程
  */
istream& operator>>(istream& input, RMB& target){
	cout << "input:";
	input
		>> target.m_nYuan
		>> target.m_nJiao;
	return input;
}

/**
  * @brief 重载大于运算符
  * @param const RMB& n1 : 运算符左边的值
  * @param const RMB& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const RMB& n1, const RMB& n2) {
	// todo
	return false;
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

/**
  * @brief 重载负号
  * @param RMB n : 值传递待取反的值
  * @retval -n
  */
RMB operator-(RMB n) {
	// todo
	return n;
}

/**
  * @brief 重载加法运算符
  * @param const RMB& n1 : 加号左边的值
  * @param const RMB& n2 : 加号右边的值
  * @retval n1 + n2
  */
RMB operator+(const RMB& n1, const RMB& n2) {
	RMB temp;
	// todo
	return temp;
}

/**
  * @brief 重载减法运算符
  * @param const RMB& n1 : 被减数
  * @param const RMB& n2 : 减数
  * @retval n1 - n2
  */
RMB operator-(const RMB& n1, const RMB& n2) {
	RMB temp;
	// todo
	return temp;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
