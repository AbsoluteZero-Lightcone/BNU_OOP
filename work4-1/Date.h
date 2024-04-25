/**
  ******************************************************************************
  * @file    Date.h
  * @author  Zhang Yifa
  * @version V2.1.0
  * @date    2024-04-23
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

class Date{

public:
    Date operator-(int)const;
    int operator-( const Date&)const;

private:
    Year _year;
    Month _month;
    Day _day;

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
    Date operator++(int);
    Date operator--(int);

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
    static int diff(Date date1, Date date2);
    int diff(const Date& date);
    static int diffMonth(Date date1, Date date2);
    int diffMonth(const Date& date);
    //int operator-(const Date&)const;

// get方法
    Year getYear()const;
    Month getMonth()const;
    Day getDay()const;
    void showDate();

// 构造析构
    Date(Year year = 2024,Month month = 4,Day day=23);
    ~Date();

    friend std::ostream& operator<<(std::ostream& out, const Date& source);

};


std::ostream& operator<<(std::ostream& out, const Date& source);

#endif /* !__DATE_H */
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
