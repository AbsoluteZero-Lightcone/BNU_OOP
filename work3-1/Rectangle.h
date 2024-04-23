/**
  ******************************************************************************
  * @file    small_class.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   small_class class
  * @encode  GB2312
  ******************************************************************************
  */

  // 替换内容：
  // small_class 类名
  // datatype 类型
  // dataname 变量名
  // 改文件名
  // 将宏定义改为大写
  // 删除临时使用的typedef
typedef int datatype1;
typedef int datatype2;

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __small_class_H
#define __small_class_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
#include <cstdint>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class small_class {
private:
	datatype1 m_dataname1;
	datatype2 m_dataname2;
public:
	// Constructors & Deconstructor
	small_class();
	small_class(datatype1 t_dataname1, datatype2 t_dataname2);
	small_class(const small_class& source);
	~small_class();

	// Getter & Setter
	datatype1 get_dataname1()const;
	void set_dataname1(datatype1 t_dataname1);
	datatype2 get_dataname2()const;
	void set_dataname2(datatype2 t_dataname2);

	// 运算符重载
	void operator=(const small_class& source);

	friend ostream& operator<<(ostream& out, const small_class& source);
	friend bool operator==(const small_class& n1, const small_class& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const small_class& source);
bool operator==(const small_class& n1, const small_class& n2);

#endif /* !__small_class_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
