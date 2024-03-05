/**
  ******************************************************************************
  * @file    date.h
  * @author  Zhang Yifa
  * @version V1.2.0
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
    Date& addDay();
    Date& subDay();
    Date& operator++(int);
    Date& operator--(int);
    Date& operator++();
    Date& operator--();

    Date& addDay(uint8_t n);
    Date& subDay(uint8_t n);

    Year getYear()const;
    Month getMonth()const;
    Day getDay()const;
    void showDate();
    void set_date_output_callback(_date_output_callback_t _date_output_callback)
    {
        this->_date_output_callback = _date_output_callback;
    }
    void set_info_output_callback(_info_output_callback_t _info_output_callback)
    {
        this->_info_output_callback = _info_output_callback;
    }

    Date();
    Date(Year year,Month month,Day day,
    _info_output_callback_t _info_output_callback = _defaultOutput,
    _date_output_callback_t _date_output_callback = _defaultOutput);
    ~Date();
    
};
#endif /* __DATE_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
