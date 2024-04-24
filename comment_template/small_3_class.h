/**
  ******************************************************************************
  * @file    small_3_class.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-25
  * @brief   small_3_class class
  * @encode  GB2312
  ******************************************************************************
  */

  // 替换内容：
  // small_3_class 类名
  // datatype 类型
  // dataname 变量名
  // 改文件名
  // 将宏定义改为大写
  // 删除临时使用的typedef
typedef int datatype1;
typedef int datatype2;
typedef int datatype3;

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __small_3_class_H
#define __small_3_class_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class small_3_class {
private:
	datatype1 m_dataname1;
	datatype2 m_dataname2;
	datatype3 m_dataname3;
public:
	// Constructors & Deconstructor
	small_3_class();
	small_3_class(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3);
	small_3_class(const small_3_class& source);
	~small_3_class();

	// Getter & Setter
	datatype1 get_dataname1()const;
	void set_dataname1(datatype1 t_dataname1);
	datatype2 get_dataname2()const;
	void set_dataname2(datatype2 t_dataname2);
	datatype3 get_dataname3()const;
	void set_dataname3(datatype3 t_dataname3);
	void set(datatype1 t_dataname1, datatype2 t_dataname2, datatype3 t_dataname3);

	// 运算符重载
	void operator=(const small_3_class& source);

	friend ostream& operator<<(ostream& out, const small_3_class& source);
	friend bool operator==(const small_3_class& n1, const small_3_class& n2);
	friend bool operator!=(const small_3_class& n1, const small_3_class& n2);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const small_3_class& source);
bool operator==(const small_3_class& n1, const small_3_class& n2);
bool operator!=(const small_3_class& n1, const small_3_class& n2);

#endif /* !__small_3_class_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
