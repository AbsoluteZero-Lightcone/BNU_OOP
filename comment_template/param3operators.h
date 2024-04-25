/**
  ******************************************************************************
  * @file    param3operators.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   param3operators class
  * @encode  GB2312
  ******************************************************************************
  */

  // 替换内容：
  // param3operators 类名
  // datatype 类型
  // dataname 变量名
  // 改文件名
  // 将宏定义改为大写
  // 删除临时使用的typedef
typedef int datatype1;
typedef int datatype2;
typedef int datatype3;

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __param3operators_H
#define __param3operators_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class param3operators {
private:
	datatype1 m_dataname1;
	datatype2 m_dataname2;
	datatype3 m_dataname3;
public:
	// Constructors & Deconstructor
	param3operators();
	param3operators(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3);
	param3operators(const param3operators& source);
	~param3operators();

	// Getter & Setter
	datatype1 get_dataname1()const;
	void set_dataname1(datatype1 t_dataname1);
	datatype2 get_dataname2()const;
	void set_dataname2(datatype2 t_dataname2);
	datatype3 get_dataname3()const;
	void set_dataname3(datatype3 t_dataname3);
	void set(datatype1 t_dataname1,datatype2 t_dataname2, datatype3 t_dataname3);

	// 运算符重载
	void operator=(const param3operators& source);
	void operator=(int n);
	param3operators& operator+=(int n);
	param3operators& operator++();
	param3operators& operator--();
	param3operators operator++(int);
	param3operators operator--(int);
	param3operators& operator!();

	friend ostream& operator<<(ostream& out, const param3operators& source);
	friend istream& operator>>(istream& input, param3operators& target);
	friend bool operator>(const param3operators& n1, const param3operators& n2);
	friend bool operator<(const param3operators& n1, const param3operators& n2);
	friend bool operator>=(const param3operators& n1, const param3operators& n2);
	friend bool operator<=(const param3operators& n1, const param3operators& n2);
	friend bool operator==(const param3operators& n1, const param3operators& n2);
	friend bool operator!=(const param3operators& n1, const param3operators& n2);
	friend param3operators operator-(param3operators n);
	friend param3operators operator+(const param3operators& n1, const param3operators& n2);
	friend param3operators operator-(const param3operators& n1, const param3operators& n2);
	friend param3operators operator*(const param3operators& n1, const param3operators& n2);
	friend param3operators operator/(const param3operators& n1, const param3operators& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const param3operators& source);
istream& operator>>(istream& input, param3operators& target);
bool operator>(const param3operators& n1, const param3operators& n2);
bool operator<(const param3operators& n1, const param3operators& n2);
bool operator>=(const param3operators& n1, const param3operators& n2);
bool operator<=(const param3operators& n1, const param3operators& n2);
bool operator==(const param3operators& n1, const param3operators& n2);
bool operator!=(const param3operators& n1, const param3operators& n2);
param3operators operator-(param3operators n);
param3operators operator+(const param3operators& n1, const param3operators& n2);
param3operators operator-(const param3operators& n1, const param3operators& n2);
param3operators operator*(const param3operators& n1, const param3operators& n2);
param3operators operator/(const param3operators& n1, const param3operators& n2);

#endif /* !__param3operators_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
