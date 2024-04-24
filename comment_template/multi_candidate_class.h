/**
  ******************************************************************************
  * @file    multi_candidate_class.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-23
  * @brief   multi_candidate_class class
  * @encode  GB2312
  ******************************************************************************
  */

  // 替换内容：
  // multi_candidate_class 类名
  // datatype 类型
  // dataname 变量名
  // 改文件名
  // 将宏定义改为大写
  // 删除临时使用的typedef
typedef int datatype1;
typedef int datatype2;
typedef int datatype3;
typedef int datatype4;
typedef int datatype5;
typedef int datatype6;

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __multi_candidate_class_H
#define __multi_candidate_class_H
/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* Class ---------------------------------------------------------------------*/
class multi_candidate_class {
private:
	datatype1 m_dataname1;
	datatype2 m_dataname2;
	datatype3 m_dataname3;
	datatype4 m_dataname4;
	datatype5 m_dataname5;
	datatype6 m_dataname6;
public:
	// Constructors & Deconstructor
	multi_candidate_class();
	multi_candidate_class(
		datatype1 t_dataname1,
		datatype2 t_dataname2,
		datatype3 t_dataname3,
		datatype4 t_dataname4,
		datatype5 t_dataname5,
		datatype6 t_dataname6
	);
	~multi_candidate_class();

	// Getter & Setter
	datatype1 get_dataname1()const;
	datatype2 get_dataname2()const;
	datatype3 get_dataname3()const;
	datatype4 get_dataname4()const;
	datatype5 get_dataname5()const;
	datatype6 get_dataname6()const;
	void set_dataname1(datatype1 t_dataname1);
	void set_dataname2(datatype2 t_dataname2);
	void set_dataname3(datatype3 t_dataname3);
	void set_dataname4(datatype4 t_dataname4);
	void set_dataname5(datatype5 t_dataname5);
	void set_dataname6(datatype6 t_dataname6);
	
	// 阻止复制
	multi_candidate_class(const multi_candidate_class& source) = delete;
	void operator=(const multi_candidate_class& source) = delete;

	friend ostream& operator<<(ostream& out, const multi_candidate_class& source);
};

/* Exported functions ------------------------------------------------------- */
ostream& operator<<(ostream& out, const multi_candidate_class& source);

#endif /* !__multi_candidate_class_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
