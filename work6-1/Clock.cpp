/**
  ******************************************************************************
  * @file    Clock.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.1.0
  * @date    2024-04-20
  * @brief   Clock class
  * @encode  GB2312
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Clock.h"

/* Constructors & Deconstructor --------------------------------------------- */
Clock::Clock() :
	m_nHour(0),
	m_nMinute(0),
	m_nSecond(0)
{}

Clock::Clock(int t_nHour, int t_nMinute, int t_nSecond) {
	setTime(t_nHour, t_nMinute, t_nSecond);
}

Clock::Clock(const Clock& source) :
	m_nHour(source.m_nHour),
	m_nMinute(source.m_nMinute),
	m_nSecond(source.m_nSecond)
{}

Clock::~Clock() {}

/* Getters & Setters -------------------------------------------------------- */
int Clock::get_nHour()const { return m_nHour; }
void Clock::set_nHour(int t_nHour) {
	if (t_nHour >= 24 || t_nHour < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nHour = t_nHour;
}
int Clock::get_nMinute()const { return m_nMinute; }
void Clock::set_nMinute(int t_nMinute) {
	if (t_nMinute >= 60 || t_nMinute < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nMinute = t_nMinute;
}
int Clock::get_nSecond()const { return m_nSecond; }
void Clock::set_nSecond(int t_nSecond) {
	if (t_nSecond >= 60 || t_nSecond < 0) {
		cout << "Incorrect Time Format." << endl;
		return;
	}
	m_nSecond = t_nSecond;
}

void Clock::setTime(int t_nHour, int t_nMinute, int t_nSecond) {
	if (!isValid(t_nHour, t_nMinute, t_nSecond))
		Standarize(t_nHour, t_nMinute, t_nSecond);
	m_nHour = t_nHour;
	m_nMinute = t_nMinute;
	m_nSecond = t_nSecond;

}

// 规定动作
/**
  * @brief 显示时间功能
  * @param None
  * @retval None
  */
void Clock::Show() const {
	cout << *this;
}

/**
  * @brief 计时功能，每一次Tick，时间向前走1秒
  * @param None
  * @retval None
  */
void Clock::Tick() {
	(*this)++;
}

/**
  * @brief 求2个时间值的差函数
  * @retval 注意时间流逝的方向：从*this时刻到c时刻所需要的时间，可为次日
  */
Clock Clock::Sub(const Clock& c) const {
	return Clock(c.m_nHour - m_nHour, c.m_nMinute - m_nMinute, c.m_nSecond - m_nSecond);
}

/**
  * @brief 将传入的引用标准化，可接受负数值
  * @retval 使用引用参数返回
  */
void Standarize(int& t_nHour, int& t_nMinute, int& t_nSecond) {
	// work6中的类设计允许自由的时分秒数值，不强制标准化，安全性欠佳，
	// 在这里Clock类中封装的成员变量值受setter严格管理，必须为合法量，不可能为负值，需要处理传入的负数
	// 于是Standardize函数的实现和作业要求略有不同：
	// 这里做的是 标准化传入的时分秒的原始数据，而不是标准化Clock对象，因为这种类设计无需手动标准化
	int temp_h = t_nHour;
	int temp_m = t_nMinute;
	int temp_s = t_nSecond;
	t_nSecond = temp_s % 60;
	t_nMinute = (temp_m + temp_s / 60) % 60;
	t_nHour = (temp_h + (temp_m + temp_s / 60) / 60) % 24;
	// todo : 继承Date后 修改这部分（丢失了天的进位）
	// 处理负数
	// 极端情况验证： -23 -59 -59
	// 下面的逻辑正确 
	if (t_nSecond < 0) {
		t_nSecond += 60;
		t_nMinute--;
	}
	if (t_nMinute < 0) {
		t_nMinute += 60;
		t_nHour--;
	}
	if (t_nHour < 0) {
		t_nHour += 24;
	}
}

/* Exported functions ------------------------------------------------------- */

/**
  * @brief 加上对应的秒数，不改变自身
  * @param n : 待加的秒数，可接受负数
  * @retval Clock
  */
Clock Clock::addSecond(int n)const {
	Clock temp(*this);
	if (n >= 0)
		for (int i = 0; i < n; i++)
			temp++;
	else for (int i = 0; i < -n; i++)
		temp--;
	return temp;
}

/**
  * @brief 加上对应的小时数
  * @param n : 待加的小时数，可接受负数，可空，默认为下一小时
  * @retval 返回自身引用实现链式编程
  */
Clock& Clock::toNextHour(int n) {
	m_nHour = (m_nHour + n) % 24;
	if (m_nHour < 0)m_nHour += 24;
	return *this;
}

/**
  * @brief 判断时间是否有效
  * @param int t_nHour : 时
  * @param int t_nMinute : 分
  * @param int t_nSecond : 秒，可省
  * @retval bool 1 for 有效
  */
bool isValid(int t_nHour, int t_nMinute, int t_nSecond) {
	if (
		t_nHour >= 24 || t_nHour < 0 ||
		t_nMinute >= 60 || t_nMinute < 0 ||
		t_nSecond >= 60 || t_nSecond < 0
		)return 0;
	else return 1;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Clock& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Clock& source) {
	out << setw(2) << setfill('0') << source.m_nHour << ":"
		<< setw(2) << setfill('0') << source.m_nMinute << ":"
		<< setw(2) << setfill('0') << source.m_nSecond;
	return out;
}

/**
  * @brief 类内重载通过对象赋值的赋值运算符
  * @param const Clock& source : 待赋的值
  * @retval 无
  */
void Clock::operator=(const Clock& source) {
	m_nHour = source.m_nHour;
	m_nMinute = source.m_nMinute;
	m_nSecond = source.m_nSecond;
}

/**
  * @brief 类内重载自增运算符，到下一秒
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
Clock& Clock::operator++() {
	m_nSecond++;
	if (m_nSecond == 60) {
		m_nSecond = 0;
		m_nMinute++;
		if (m_nMinute == 60) {
			m_nMinute = 0;
			m_nHour++;
			if (m_nHour == 24) {
				m_nHour = 0;
				// m_nDay++; //todo 从Date中继承
			}
		}
	}
	return *this;
}
Clock Clock::operator++(int) {
	Clock temp(*this);
	(*this)++;
	return temp;
}

/**
  * @brief 类内重载自减运算符，到上一秒
  * @param 无
  * @retval 返回自身引用实现链式编程
  */
Clock& Clock::operator--() {
	m_nSecond--;
	if (m_nSecond == -1) {
		m_nSecond = 59;
		m_nMinute--;
		if (m_nMinute == -1) {
			m_nMinute = 59;
			m_nHour--;
			if (m_nHour == -1) {
				m_nHour = 23;
				// m_nDay--; //todo 从Date中继承
			}
		}
	}
	return *this;
}
Clock Clock::operator--(int) {
	Clock temp(*this);
	(*this)--;
	return temp;
}

/**
  * @brief 重载大于运算符
  * @param const Clock& n1 : 运算符左边的值
  * @param const Clock& n2 : 运算符右边的值
  * @retval bool, true for n1 > n2
  */
bool operator>(const Clock& n1, const Clock& n2) {
	return !(n1 <= n2);
}
/**
  * @brief 重载小于运算符
  * @param const Clock& n1 : 运算符左边的值
  * @param const Clock& n2 : 运算符右边的值
  * @retval bool, true for n1 < n2
  */
bool operator<(const Clock& n1, const Clock& n2) {
	return !(n1 >= n2);
}

/**
  * @brief 重载大于等于运算符
  * @param const Clock& n1 : 运算符左边的值
  * @param const Clock& n2 : 运算符右边的值
  * @retval bool, true for n1 >= n2
  */
bool operator>=(const Clock& n1, const Clock& n2) {
	if (n1.m_nHour < n2.m_nHour)return false;
	else if (n1.m_nMinute < n2.m_nMinute)return false;
	else if (n1.m_nSecond < n2.m_nSecond)return false;
	else return true;
}
/**
  * @brief 重载小于等于运算符
  * @param const Clock& n1 : 运算符左边的值
  * @param const Clock& n2 : 运算符右边的值
  * @retval bool, true for n1 <= n2
  */
bool operator<=(const Clock& n1, const Clock& n2) {
	return (n1 < n2) || (n1 == n2);
}

/**
  * @brief 重载等于运算符
  * @param const Clock& n1 : 运算符左边的值
  * @param const Clock& n2 : 运算符右边的值
  * @retval bool, true for n1 == n2
  */
bool operator==(const Clock& n1, const Clock& n2) {
	if (n1.m_nHour != n2.m_nHour)return false;
	else if (n1.m_nMinute != n2.m_nMinute)return false;
	else if (n1.m_nSecond != n2.m_nSecond)return false;
	return true;
}

/**
  * @brief 重载减法运算符，时间差，超过24小时会溢出
  * @param const Clock& n1 : 被减数
  * @param const Clock& n2 : 减数
  * @retval 时间差
  */
Clock operator-(const Clock& n1, const Clock& n2) {
	// todo : 继承Date后要修改这段，将不同日期考虑进来，解决超过24小时会溢出问题
	return Clock(
		n1.m_nHour - n2.m_nHour,
		n1.m_nMinute - n2.m_nMinute,
		n1.m_nSecond - n2.m_nSecond
	);
}

/**
  * @brief 类内重载+=运算符，加上对应的秒数
  * @param c : Clock Object
  * @param n : 待加的秒数
  * @retval 返回自身引用实现链式编程
  */
Clock operator+(Clock c, int n) {
	for (int i = 0; i < n; i++)
		c++;
	return c;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
