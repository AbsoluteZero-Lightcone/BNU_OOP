/**
  ******************************************************************************
  * @file    Deposit.h
  * @author  Zhang Yifa 202311998186
  * @version V1.2.0
  * @date    2024-04-23
  * @brief   Deposit class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DEPOSIT_H
#define __DEPOSIT_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include "Date.h"

/* Class ---------------------------------------------------------------------*/
class Deposit {
private:
	int m_nAccount;
	string m_strName;
	string m_strPassword;
	double m_dDeposit;
	Date m_dateDate;

	static int s_nCount;
	static double s_dInterest;

public:

	static void setInterest(double Interest);

	// Constructors & Deconstructor
	Deposit();
	Deposit(
		string t_strName,
		string t_strPassword,
		double t_dDeposit,
		Date t_dateDate
	);
	Deposit(const Deposit& source);
	~Deposit();

	void operator=(const Deposit& source);

	void update();

	// Getter & Setter
	int get_nAccount()const;
	string get_strName()const;
	string get_strPassword()const;
	static double get_dInterest();
	double get_dDeposit()const;
	Date get_dateDate()const;

	void set_nAccount(int t_nAccount);
	void set_strName(string t_strName);
	void set_strPassword(string t_strPassword);
	static void set_dInterest(double t_dInterest);
	void set_dDeposit(double t_dDeposit);
	void set_dateDate(Date t_dateDate);
	

	friend ostream& operator<<(ostream& out, const Deposit& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Deposit& source);

#endif /* !__DEPOSIT_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
