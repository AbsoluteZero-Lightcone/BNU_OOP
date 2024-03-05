/**
  ******************************************************************************
  * @file    date.h
  * @author  Zhang Yifa
  * @version V1.2.2
  * @date    2024-03-05
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

    bool isLeapYear()const;
    bool is31Days()const;
    Day getDays()const;

// 对日期的通用操作函数，应该不用实例化就能调用，使之能类外复用：
    static bool isLeapYear(Year year);
    static bool is31Days(Month month);
    static Day getDays(Year year,Month month);
    static bool isValid(Year year,Month month,Day day);


public:
    void setDate(Year year,Month month,Day day);
// 自增自减逻辑
    Date& toNextDay();
    Date& toPreviousDay();
    inline Date& operator++(int);
    inline Date& operator--(int);
    inline Date& operator++();
    inline Date& operator--();

// 加减逻辑
    Date& addDay(int n = 1);
    Date& subDay(int n = 1);
    Date& operator+(int n){
        return this->addDay(n);
    }
    Date& operator-(int n){
        return this->subDay(n);
    }
// 计算相差天数
    int diff(Date& date){
        // todo
    }
    int operator-(Date& date){
        return diff(date);
    }
// get方法
    Year getYear()const;
    Month getMonth()const;
    Day getDay()const;
    void showDate();

// 设置输出接口的回调函数
    void set_date_output_callback(_date_output_callback_t _date_output_callback)
    {
        this->_date_output_callback = _date_output_callback;
    }
    void set_info_output_callback(_info_output_callback_t _info_output_callback)
    {
        this->_info_output_callback = _info_output_callback;
    }

// 构造析构
    Date(Year year = 2024,Month month = 3,Day day=5,
    _info_output_callback_t _info_output_callback = _defaultOutput,
    _date_output_callback_t _date_output_callback = _defaultOutput);
    ~Date();
    
};
#endif /* __DATE_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
