/**
  ******************************************************************************
  * @file    Deposit.cpp
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Deposit class
  * @encode  GB2312
  ******************************************************************************
  */

#include "Deposit.h"

  /* Static Members ------------------------------------------------------------*/
int Deposit::s_nCount = 0;
double Deposit::s_dInterest = 0.005;

/* Constructors & Deconstructor --------------------------------------------- */
Deposit::Deposit() :
	m_nAccount(++s_nCount),
	m_strName("缺省"),
	m_strPassword("缺省"),
	m_dDeposit(0),
	m_dateDate(0)
{}

Deposit::Deposit(
	string t_strName,
	string t_strPassword,
	double t_dDeposit,
	Date t_dateDate
) :
	m_nAccount(++s_nCount),
	m_strName(t_strName),
	m_strPassword(t_strPassword),
	m_dateDate(t_dateDate)
{
	// 到2022.1的金额
	m_dDeposit = t_dDeposit * pow(s_dInterest + 1, t_dateDate.diffMonth(Date(2022, 7, 1)));
}

Deposit::~Deposit() {}

/* Getters & Setters -------------------------------------------------------- */
int Deposit::get_nAccount()const { return m_nAccount; }
string Deposit::get_strName()const { return m_strName; }
string Deposit::get_strPassword()const { return m_strPassword; }
double Deposit::get_dInterest() { return s_dInterest; }
double Deposit::get_dDeposit()const { return m_dDeposit; }
Date Deposit::get_dateDate()const { return m_dateDate; }
void Deposit::set_nAccount(int t_nAccount) { m_nAccount = t_nAccount; }
void Deposit::set_strName(string t_strName) { m_strName = t_strName; }
void Deposit::set_strPassword(string t_strPassword) { m_strPassword = t_strPassword; }
void Deposit::set_dInterest(double t_dInterest) { s_dInterest = t_dInterest; }
void Deposit::set_dDeposit(double t_dDeposit) { m_dDeposit = t_dDeposit; }
void Deposit::set_dateDate(Date t_dateDate) { m_dateDate = t_dateDate; }


/* Exported functions ------------------------------------------------------- */
void Deposit::update() {
	m_dDeposit *= s_dInterest + 1.0;
}

/**
  * @brief 重载标准输出流 <<运算符
  * @param ostream& out : 标准输出流对象
  * @param const Deposit& source : 待输出的对象
  * @retval ostream&
  */
ostream& operator<<(ostream& out, const Deposit& source) {
	out << source.m_nAccount << "\t"
		<< source.m_strName << "\t"
		<< source.m_strPassword << "\t"
		<< source.m_dDeposit << "\t"
		<< Deposit::s_dInterest * 100.0 << "%" << "\t"
		<< source.m_dateDate;
	return out;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
