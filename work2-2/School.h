/**
  ******************************************************************************
  * @file    School.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   School class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SCHOOL_H
#define __SCHOOL_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <cstring>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class School {
private:
	char* m_strName;
	char* m_strAddr;
public:
	// Constructors & Deconstructor
	School(const char* name, const char* addr);
	School(const School& source);
	~School();

	// Getter & Setter
	char* get_strName()const;
	void set_strName(char* t_strName);
	char* get_strAddr()const;
	void set_strAddr(char* t_strAddr);
	void set(char* t_strName, char* t_strAddr);

	void Show() const;

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	friend ostream& operator<<(ostream& out, const School& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const School& source);

#endif /* !__SCHOOL_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
