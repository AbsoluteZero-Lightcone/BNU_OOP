/**
  ******************************************************************************
  * @file    main.cpp
  * @author  Zhang Yifa
  * @version V1.2.0
  * @date    2024-03-05
  * @brief   A demonstration of the class Date.
  * @encode  UTF-8
  ******************************************************************************
  */
#include <iostream>
#include <string>
using namespace std;

#include "date.h"

// 用回调函数实现了在类外自定义输出格式
void output(int year, int month, int day) {
    cout << year << "年" << month << "月" << day << "日" << endl;
}
void output(string s){
    cout << "提示信息：" << s << endl;
}

int main(){
    //system("chcp 65001");
    Date today(2024,3,5, output, output);
    today.showDate();
    today++;// 重载了自增自减运算符
    today.showDate();
    today++++++++;// 并可以链式调用
    today.showDate();
    today.setDate(0, 0, 0);// 带有合法性检查的set函数
    cout << (Date::isValid(0, 0, 0)?"有效":"无效") << endl;// 类外不用实例化，就能使用类提供的静态函数
    system("pause");
    return 0;
}

// todo: +- toNextMonth toNextYear 返回拷贝对象的运算操作
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
