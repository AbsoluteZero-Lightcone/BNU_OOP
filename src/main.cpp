/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa
  * @version V1.3.4
  * @date    2024-03-07
  * @brief   The intrance of the program.
  * @encode  UTF-8
  ******************************************************************************
  */
#include <iostream>
using namespace std;
//#include "demo.h"









// 将有问题的部分隔离：
#define WITH_PARAM_CONST 0
#define WITH_FUNC_CONST 1

#include "date.h"
/* 
为方便演示，使用宏：

WITH_PARAM_CONST	为 0 时	引用参数不加const修饰
WITH_PARAM_CONST	为 1 时	引用参数加const修饰

WITH_FUNC_CONST	为 0 时	成员函数不加const修饰
WITH_FUNC_CONST	为 1 时	成员函数加const修饰


经测试，问题总结为以下的现象：
两个宏设置为 0 0 即原型为 int operator-(Date&); 的时候，				不报错，程序正常运行
两个宏设置为 0 1 即原型为 int operator-(Date&)const; 的时候，		不报错，程序正常运行
两个宏设置为 1 0 即原型为 int operator-(const Date&); 的时候，		报错：错误C2666“Date::operator -”: 重载函数具有类似的转换
两个宏设置为 1 1 即原型为 int operator-(const Date&)const;的时候，	不报错，程序正常运行

*/
void test() {
	Date today(2024, 3, 6);
	Date temp = today - 9;// 主要是测试这个减法运算是否能够被编译器正确重载
	temp.showDate();
}








int main() {
	//system("chcp 65001"); //使用GB2312时注释掉
	test();
	system("pause");
	return 0;
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
