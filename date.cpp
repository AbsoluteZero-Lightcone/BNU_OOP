/**
  ******************************************************************************
  * @file    date.cpp
  * @author  Zhang Yifa
  * @version V1.1.0
  * @date    2024-03-05
  * @brief   Abstract a class for handling date data.
  * @encode  UTF-8
  ******************************************************************************
  */

 // includes:
#include "date.h"
#include <cstdint>
#include <string>

// private:

/**
  * @brief  判断是否是闰年
  * @param  year 输入年份
  * @retval bool 1 for 闰年 and 0 for 不是闰年
  */
bool Date::_isLeapYear(Year year){
    if(year % 100 == 0){
        if(year % 400 == 0)return 1;
        return 0;
    }
    else if(year % 4 == 0)return 1;
    return 0;
}
/**
  * @brief  判断是否是31天的月份
  * @param  month 输入月份
  * @retval bool 1 for 是31天的月份 and 0 for 不是31天的月份
  */
bool Date::_is31Days(Month month){
    if(month == 1)return 1;
    if(month == 3)return 1;
    if(month == 5)return 1;
    if(month == 7)return 1;
    if(month == 8)return 1;
    if(month == 10)return 1;
    if(month == 12)return 1;
    return 0;
}
/**
  * @brief  获取输入年月的月份的总天数
  * @param  year  输入年份
  * @param  month 输入月份
  * @retval 月份的总天数
  */
Day Date::_getDays(Year year,Month month){
    if( month == 2 ){
        if(_isLeapYear(year)) return 29;
        return 28;
    }
    else if(_is31Days(month))return 31;
    return 30;
}
/**
  * @brief  判断当前对象所在年份是否是闰年
  * @retval bool 1 for 闰年 and 0 for 不是闰年
  */
bool Date::_isLeapYear(){
    if(_year % 100 == 0){
        if(_year % 400 == 0)return 1;
        return 0;
    }
    else if(_year % 4 == 0)return 1;
    return 0;
}
/**
  * @brief  判断当前对象所在月份是否是31天
  * @retval bool 1 for 是31天的月份 and 0 for 不是31天的月份
  */
bool Date::_is31Days(){
    if(_month == 1)return 1;
    if(_month == 3)return 1;
    if(_month == 5)return 1;
    if(_month == 7)return 1;
    if(_month == 8)return 1;
    if(_month == 10)return 1;
    if(_month == 12)return 1;
    return 0;
}
/**
  * @brief  获取当前对象所在月份的总天数
  * @retval 月份的总天数
  */
Day Date::_getDays(){
    if( _month == 2 ){
        if(_isLeapYear(_year)) return 29;
        return 28;
    }
    else if(_is31Days(_month))return 31;
    return 30;
}
/**
  * @brief  判断输入的年月日是否正确
  * @param  year  输入年份
  * @param  month 输入月份
  * @param  day   输入日期
  * @retval bool 1 for 日期有效 and 0 for 日期无效
  */
bool Date::_isValid(Year year,Month month,Day day){
    if( year == 0 )return 0;
    if( month > 12 || month < 1 )return 0;
    if( day > _getDays(year,month) || day < 1 )return 0;
}

// public:
/**
  * @brief  设置日期
  * @param  year  输入年份
  * @param  month 输入月份
  * @param  day   输入日期
  * @retval void
  */
void Date::setDate(Year year,Month month,Day day){
    if(!_isValid(year,month,day)){
        _info_output_interface_callback_handler("Invalid Date");
        return;
    }
    _year = year;
    _month = month;
    _day = day;
}
/**
  * @brief  日期+1
  * @retval *this 可用于链式编程
  */
Date& Date::addDay(){
    _day++;
    if(_day > _getDays()){
        _day = 1;
        _month++;
        if(_month > 12){
            _month = 1;
            _year++;
        }
    }
    return *this;
}
/**
  * @brief  日期-1
  * @retval *this 可用于链式编程
  */
Date& Date::subDay(){
    _day--;
    if(_day < 1){
        _month--;
        _day = _getDays();
        if(_month < 1){
            _month = 12;
            _year--;
        }
    }
    return *this;
}
/**
  * @brief  重载前置自增运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator++(){
    _day++;
    if(_day > _getDays()){
        _day = 1;
        _month++;
        if(_month > 12){
            _month = 1;
            _year++;
        }
    }
    return *this;
}
/**
  * @brief  重载前置自减运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator--(){
    _day--;
    if(_day < 1){
        _month--;
        _day = _getDays();
        if(_month < 1){
            _month = 12;
            _year--;
        }
    }
    return *this;
}
/**
  * @brief  重载后置自增运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator++(int){
    _day++;
    if(_day > _getDays()){
        _day = 1;
        _month++;
        if(_month > 12){
            _month = 1;
            _year++;
        }
    }
    return *this;
}
/**
  * @brief  重载后置自减运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator--(int){
    _day--;
    if(_day < 1){
        _month--;
        _day = _getDays();
        if(_month < 1){
            _month = 12;
            _year--;
        }
    }
    return *this;
}
/**
  * @brief  日期往后n天
  * @param  n 日期往后n天
  * @retval *this 可用于链式编程
  */
Date& Date::addDay(uint8_t n){
    // This is a temp solution.
    // Todo: remove loops
    for(uint8_t i = 0 ; i < n ; i++)(*this)++;
    return *this;
}
/**
  * @brief  日期往前n天
  * @param  n 日期往前n天
  * @retval *this 可用于链式编程
  */
Date& Date::subDay(uint8_t n){
    // This is a temp solution.
    // Todo: remove loops
    for(uint8_t i = 0 ; i < n ; i++)(*this)--;
    return *this;
}

inline Year Date::getYear(){return _year;}
inline Month Date::getMonth(){return _month;}
inline Day Date::getDay(){return _day;}

/**
  * @brief  展示当前日期
  * @param  指定输出显示接口的回调函数
  * @retval void
  */
inline void Date::showDate(){
        _date_output_interface_callback_handler(_year,_month,_day);
        }

inline Date::Date():_year(2024),_month(1),_day(1){}
inline Date::Date(Year year,Month month,Day day){
    setDate(year,month,day);
}
inline Date::~Date(){
    // 空实现
}


/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
