/**
  ******************************************************************************
  * @file    exported_class.h
  * @author  Zhang Yifa 202311998186
  * @version V1.0.0
  * @date    2024-04-20
  * @brief   exported_class class
  * @encode  GB2312
  ******************************************************************************
  */

#ifndef __exported_class_H
#define __exported_class_H

#include <iostream>
using namespace std;

typedef int datatype1;
typedef int datatype2;
// 替换内容：exported_class 类名
// datatype 类型
// m_dataname 变量名

class exported_class {
private:
	datatype1 m_dataname1;
	datatype2 m_dataname2;
public:
	exported_class();
	exported_class(const exported_class& source);
	~exported_class();
	void operator=(const exported_class& source);
	datatype1 get_dataname1();
	void set_dataname1(datatype1 t_dataname1);
	datatype2 get_dataname2();
	void set_dataname2(datatype2 t_dataname2);
};


#endif /* !__exported_class_H */

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
