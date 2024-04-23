/**
  ******************************************************************************
  * @file    exported_class.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   exported_class class
  * @encode  GB2312
  ******************************************************************************
  */

  // 替换内容：
  // exported_class 类名
  // datatype 类型
  // dataname 变量名
  // 改文件名
  // 将宏定义改为大写
  // 删除临时使用的typedef
typedef int datatype1;
typedef int datatype2;

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __exported_class_H
#define __exported_class_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class exported_class {
private:
	datatype1 m_dataname1;
	datatype2 m_dataname2;
public:
	// Constructors & Deconstructor
	exported_class();
	exported_class(datatype1 t_dataname1, datatype2 t_dataname2);
	exported_class(const exported_class& source);
	~exported_class();

	// Getter & Setter
	datatype1 get_dataname1()const;
	void set_dataname1(datatype1 t_dataname1);
	datatype2 get_dataname2()const;
	void set_dataname2(datatype2 t_dataname2);
	void set(datatype1 t_dataname1,datatype2 t_dataname2);

	// 运算符重载
	void operator=(const exported_class& source);
	void operator=(int n);
	exported_class& operator+=(int n);
	exported_class& operator++(int);
	exported_class& operator--(int);
	exported_class& operator!();

	friend ostream& operator<<(ostream& out, const exported_class& source);
	friend bool operator>(const exported_class& n1, const exported_class& n2);
	friend bool operator<(const exported_class& n1, const exported_class& n2);
	friend bool operator>=(const exported_class& n1, const exported_class& n2);
	friend bool operator<=(const exported_class& n1, const exported_class& n2);
	friend bool operator==(const exported_class& n1, const exported_class& n2);
	friend bool operator!=(const exported_class& n1, const exported_class& n2);
	friend exported_class operator-(exported_class n);
	friend exported_class operator+(const exported_class& n1, const exported_class& n2);
	friend exported_class operator-(const exported_class& n1, const exported_class& n2);
	friend exported_class operator*(const exported_class& n1, const exported_class& n2);
	friend exported_class operator/(const exported_class& n1, const exported_class& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const exported_class& source);
bool operator>(const exported_class& n1, const exported_class& n2);
bool operator<(const exported_class& n1, const exported_class& n2);
bool operator>=(const exported_class& n1, const exported_class& n2);
bool operator<=(const exported_class& n1, const exported_class& n2);
bool operator==(const exported_class& n1, const exported_class& n2);
bool operator!=(const exported_class& n1, const exported_class& n2);
exported_class operator-(exported_class n);
exported_class operator+(const exported_class& n1, const exported_class& n2);
exported_class operator-(const exported_class& n1, const exported_class& n2);
exported_class operator*(const exported_class& n1, const exported_class& n2);
exported_class operator/(const exported_class& n1, const exported_class& n2);

#endif /* !__exported_class_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
