/**
  ******************************************************************************
  * @file    Teacher.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   Teacher class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TEACHER_H
#define __TEACHER_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Teacher {
private:
	string m_strName;
public:
	// Constructors & Deconstructor
	Teacher();
	Teacher(string t_strName);
	Teacher(const Teacher& source);
	~Teacher();

	// Getter & Setter
	string get_strName()const;
	void set_strName(string t_strName);

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Teacher& source);

	friend ostream& operator<<(ostream& out, const Teacher& source);
	friend bool operator==(const Teacher& n1, const Teacher& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Teacher& source);
bool operator==(const Teacher& n1, const Teacher& n2);

#endif /* !__TEACHER_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
