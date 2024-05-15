/**
  ******************************************************************************
  * @file    Person.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-05-15
  * @brief   Person class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PERSON_H
#define __PERSON_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Person {
private:
	string m_strName;
	int m_nAge;
public:
	// Constructors & Deconstructor
	Person();
	Person(string t_strName, int t_nAge);
	Person(const Person& source);
	~Person();

	// Getter & Setter
	string get_strName()const;
	void set_strName(string t_strName);
	int get_nAge()const;
	void set_nAge(int t_nAge);
	void set(string t_strName, int t_nAge);

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Person& source);

	friend ostream& operator<<(ostream& out, const Person& source);
	friend bool operator==(const Person& n1, const Person& n2);
	friend bool operator!=(const Person& n1, const Person& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Person& source);
bool operator==(const Person& n1, const Person& n2);
bool operator!=(const Person& n1, const Person& n2);

#endif /* !__PERSON_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
