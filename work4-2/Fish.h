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
	int m_nLastFedDey;
	bool m_bAlive;
	
public:
	static int s_nTotal;
	static int s_nAlive;
	static int s_nCurrentDay;
	// Constructors & Deconstructor
	Fish();
	Fish(string t_strName, string t_strColor);
	~Fish();

	void update(bool isfed);

	// Getter & Setter
	void set(string t_strName, string t_strColor);

	// 运算符重载
	friend ostream& operator<<(ostream& out, const Fish& source);
};
/*
吃食后，鱼增长10克。
如果一条鱼连续5天吃不到食物，体重就要减少10克。
鱼的体重减少到0克时，鱼就饿死了。
鱼的体重长到300克时，鱼就撑死了。
*/
/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Fish& source);
#endif /* !__FISH_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
