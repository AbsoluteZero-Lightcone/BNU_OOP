/**
  ******************************************************************************
  * @file    date.h
  * @author  Zhang Yifa
  * @version V1.3.4
  * @date    2024-03-07
  * @brief   Abstract a class for handling date data.
  * @encode  UTF-8
  ******************************************************************************
  */
#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <cstdint>
#include <string>

typedef int16_t Year;
typedef uint8_t Month;
typedef uint8_t Day;

void _defaultOutput(std::string s);
void _defaultOutput(int year,int month,int day);

class Date{

//=============有问题的部分=============

public:
    // 重载 Date - int = Date 运算
    // 这里经测试const加不加都行
    Date operator-(int)const;


    // 重载 Date - Date = int 运算
    // int operator-(const Date&);报错
    // int operator-(const Date&)const;正确
    // 这里的const试过了不能去掉，
    // 一开始我对const修饰成员函数的理解不够深入，只知道是能够防止该成员函数修改当前对象的成员变量
    // 但现在具体不明白的点就是这里的const是有什么特殊的语义吗（VS提示我“注意：限定调整(const/volatile)可能会造成多义性”），
    // 以至于导致了这里的const能影响编译器对函数重载的推导
    // 换句话来说，函数不带const时，为什么编译器会觉得（int）和（const Date&）这两个形参列表很像
    // 理解这个问题能帮助我们理解const的正确用法
    int operator-(
#if WITH_PARAM_CONST == 1
        const
#endif
        Date&)
#if WITH_FUNC_CONST == 1
        const
#endif
        ;
    // 我又研究了一会儿发现一个比较好的现象，函数和参数都不加const时，程序也能跑，这可能能够帮助解释上面的问题
    // int operator-(Date&);

//=============有问题的部分=============











private:
    Year _year;
    Month _month;
    Day _day;
    
    typedef void (*_info_output_callback_t)(std::string);
    typedef void (*_date_output_callback_t)(int,int,int);
    _info_output_callback_t _info_output_callback;
    _date_output_callback_t _date_output_callback;

public:

    void setDate(Year year,Month month,Day day);

// 对现行对象使用的函数
    bool isLeapYear()const;
    bool is31Days()const;
    Day getDays()const;

// 对日期的通用操作函数，应该不用实例化就能调用，使之能类外复用：
    static bool isLeapYear(Year year);
    static bool is31Days(Month month);
    static Day getDays(Year year,Month month);
    static bool isValid(Year year,Month month,Day day);

// 自增自减逻辑
    Date& toNextDay();
    Date& toPreviousDay();
    Date& toNextMonth();
    Date& toPreviousMonth();
    Date& toNextYear();
    Date& toPreviousYear();

    Date& operator++();
    Date& operator--();
    Date& operator++(int);
    Date& operator--(int);

    Date getNextDay()const;
    Date getPreviousDay()const;
    Date getNextMonth()const;
    Date getPreviousMonth()const;
    Date getNextYear()const;
    Date getPreviousYear()const;

// 加减逻辑
    Date& addDay(int n = 1);
    Date& subDay(int n = 1);
    Date& addMonth(int n = 1);
    Date& subMonth(int n = 1);
    Date& addYear(int n = 1);
    Date& subYear(int n = 1);
    
    Date& operator+=(int n);
    Date& operator-=(int n);

    Date operator+(int n)const;
    //Date operator-(int)const;

// 比较大小
    bool operator==(const Date& date)const;
    bool operator<(const Date& date)const;
    bool operator<=(const Date& date)const;
    bool operator!=(const Date& date)const;
    bool operator>(const Date& date)const;
    bool operator>=(const Date& date)const;


// 计算相差天数
    static int diff(Date date1,Date date2);
    int diff(const Date& date);
    //int operator-(const Date&)const;

// get方法
    Year getYear()const;
    Month getMonth()const;
    Day getDay()const;
    void showDate();

// 设置输出接口的回调函数
    void set_date_output_callback(_date_output_callback_t);
    void set_info_output_callback(_info_output_callback_t);

// 构造析构
    Date(Year year = 2024,Month month = 3,Day day=5,
    _info_output_callback_t _info_output_callback = _defaultOutput,
    _date_output_callback_t _date_output_callback = _defaultOutput);
    ~Date();
    
};
#endif /* __DATE_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
