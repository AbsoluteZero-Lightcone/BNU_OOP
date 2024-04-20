/**
  ******************************************************************************
  * @file    Person.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
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
	string get_strName();
	void set_strName(string t_strName);
	int get_nAge();
	void set_nAge(int t_nAge);

};

#endif /* !__PERSON_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
