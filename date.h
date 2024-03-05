/**
  ******************************************************************************
  * @file    date.h
  * @author  Zhang Yifa
  * @version V1.2.7
  * @date    2024-03-06
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
    Date& operator++();
    Date& operator--();
    Date& operator++(int);
    Date& operator--(int);

    Date getNextDay()const;
    Date getPreviousDay()const;

// 加减逻辑
    Date& addDay(int n = 1);
    Date& subDay(int n = 1);
    Date& operator+=(int n);
    Date& operator-=(int n);

    Date operator+(int n)const;
    Date operator-(int n)const;

// 判断相等
    bool operator==(const Date& date)const;

// 计算相差天数

    static int diff(const Date& date1,const Date& date2){
         // todo
    }
    int diff(const Date& date){
        int d_Year,d_Month,d_Day,sum = 0;
        d_Year = date.getYear() - this->getYear();
        d_Month = date.getMonth() - this->getMonth();
        d_Day = date.getDay() - this->getDay();
        // todo
    }
    int operator-(const Date& date);

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
