/**
  ******************************************************************************
  * @file    Clock.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   Clock class
  * @encode  GB2312
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CLOCK_H
#define __CLOCK_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

/* Declarations --------------------------------------------------------------*/
class WorldClock;

/* Class ---------------------------------------------------------------------*/
class Clock {
private:
	int m_nHour;
	int m_nMinute;
	int m_nSecond;
public:
	// Constructors & Deconstructor
	Clock();
	Clock(int t_nHour, int t_nMinute, int t_nSecond);
	Clock(const Clock& source);
	~Clock();

	// �涨����
	void Show() const;				//��ʾʱ�书��
	void Tick();					//��ʱ���ܣ�ÿһ��Tick��ʱ����ǰ��1��
	Clock Sub(const Clock& c) const;//��2��ʱ��ֵ�Ĳ��
	Clock& addHour(int n);

	// Getter & Setter
	int get_nHour()const;
	void set_nHour(int t_nHour);
	int get_nMinute()const;
	void set_nMinute(int t_nMinute);
	int get_nSecond()const;
	void set_nSecond(int t_nSecond);

	void setTime(int t_nHour, int t_nMinute, int t_nSecond);


	// ���������
	void operator=(const Clock& source);
	Clock& operator++(int);

	friend ostream& operator<<(ostream& out, const Clock& source);
	friend bool operator>(const Clock& n1, const Clock& n2);
	friend bool operator==(const Clock& n1, const Clock& n2);
	friend Clock operator-(const Clock& n1, const Clock& n2);
	// ���������������
	friend Clock operator-(const WorldClock& n1, const WorldClock& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const Clock& source);
bool operator>(const Clock& n1, const Clock& n2);
bool operator==(const Clock& n1, const Clock& n2);
Clock operator-(const Clock& n1, const Clock& n2);
Clock operator+(Clock c, int s);

bool isValid(int t_nHour, int t_nMinute, int t_nSecond);
void Standarize(int& t_nHour, int& t_nMinute, int& t_nSecond);

#endif /* !__CLOCK_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
