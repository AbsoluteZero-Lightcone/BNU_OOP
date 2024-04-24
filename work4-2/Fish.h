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
public:
	static int s_nCnt;
	// Constructors & Deconstructor
	Fish();
	Fish(string t_strName, string t_strColor);
	Fish(const Fish& source);
	~Fish();

	void day(bool isfed);

	// Getter & Setter
	string get_strName()const;
	void set_strName(string t_strName);
	string get_strColor()const;
	void set_strColor(string t_strColor);
	int get_nWeight()const;
	void set_nWeight(int t_nWeight);
	void set(string t_strName, string t_strColor, int t_nWeight);

	// ‘ÀÀ„∑˚÷ÿ‘ÿ
	void operator=(const Fish& source);

	friend ostream& operator<<(ostream& out, const Fish& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Fish& source);
#endif /* !__FISH_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
