/**
  ******************************************************************************
  * @file    Fish.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   Fish class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FISH_H
#define __FISH_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class Fish {
private:
	string m_strName;
	string m_strColor;
	int m_nWeight;
	bool m_bAlive;
public:
	static int s_nTotal;
	static int s_nAlive;
	// Constructors & Deconstructor
	Fish();
	Fish(string t_strName, string t_strColor);
	~Fish();

	void day(bool isfed);

	// Getter & Setter
	void set(string t_strName, string t_strColor);

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	friend ostream& operator<<(ostream& out, const Fish& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Fish& source);
#endif /* !__FISH_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
