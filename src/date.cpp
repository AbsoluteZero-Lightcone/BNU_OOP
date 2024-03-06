/**
  ******************************************************************************
  * @file    date.cpp
  * @author  Zhang Yifa
  * @version V1.3.4
  * @date    2024-03-07
  * @brief   Abstract a class for handling date data.
  * @encode  UTF-8
  ******************************************************************************
  */

 // includes:
#include "date.h"
#include <cstdint>
#include <string>
#include <iostream>







//=============有问题的部分=============

// 重载 Date - int = Date 运算
Date Date::operator-(int n)const {
    if (n == 0)return Date(*this);
    Date temp = Date(*this);
    if (n > 0)for (int i = 0; i < n; i++)temp--;
    if (n < 0)for (int i = 0; i < -n; i++)temp++;
    return temp;
}
// 重载 Date - Date = int 运算
int Date::operator-(
#if WITH_PARAM_CONST == 1
    const
#endif
    Date& date)
#if WITH_FUNC_CONST == 1
    const
#endif
{
    return diff(date, *this);
}

//=============有问题的部分=============
























// private:

/**
  * @brief  判断是否是闰年
  * @param  year 输入年份
  * @retval bool 1 for 闰年 and 0 for 不是闰年
  */
bool Date::isLeapYear(Year year){
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
bool Date::is31Days(Month month){
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
Day Date::getDays(Year year,Month month){
    if( month == 2 ){
        if(isLeapYear(year)) return 29;
        return 28;
    }
    else if(is31Days(month))return 31;
    return 30;
}
/**
  * @brief  判断当前对象所在年份是否是闰年
  * @retval bool 1 for 闰年 and 0 for 不是闰年
  */
bool Date::isLeapYear()const{
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
bool Date::is31Days()const{
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
Day Date::getDays()const{
    if( _month == 2 ){
        if(isLeapYear(_year)) return 29;
        return 28;
    }
    else if(is31Days(_month))return 31;
    return 30;
}
/**
  * @brief  判断输入的年月日是否正确
  * @param  year  输入年份
  * @param  month 输入月份
  * @param  day   输入日期
  * @retval bool 1 for 日期有效 and 0 for 日期无效
  */
bool Date::isValid(Year year,Month month,Day day){
    if( year == 0 )return 0;
    if( month > 12 || month < 1 )return 0;
    if( day > getDays(year,month) || day < 1 )return 0;
    return 1;
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
    if(!isValid(year,month,day)){
        _info_output_callback("Invalid Date");
        return;
    }
    _info_output_callback("Valid Date");
    _year = year;
    _month = month;
    _day = day;
    _info_output_callback("Update Successfully");
}
/**
  * @brief  日期+1
  * @retval *this 可用于链式编程
  */
Date& Date::toNextDay() {
    _day++;
    if (_day > getDays()) {
        _day = 1;
        _month++;
        if (_month > 12) {
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
Date& Date::toPreviousDay() {
    _day--;
    if (_day < 1) {
        _month--;
        _day = getDays();
        if (_month < 1) {
            _month = 12;
            _year--;
        }
    }
    return *this;
}
/**
  * @brief  月+1，若新的月份天数减少，没有这天，则转到这个月的最后一天
  * @retval *this 可用于链式编程
  */
Date& Date::toNextMonth() {
    _month++;
    if (_month > 12) {
        _month = 1;
        _year++;
        if (!isValid(_year, _month, _day))_day = getDays();
    }
    return *this;
}
/**
  * @brief  月-1，若新的月份天数减少，没有这天，则转到这个月的最后一天
  * @retval *this 可用于链式编程
  */
Date& Date::toPreviousMonth() {
    _month--;
    _day = getDays();
    if (_month < 1) {
        _month = 12;
        _year--;
        if (!isValid(_year, _month, _day))_day = getDays();
    }
    return *this;
}
/**
  * @brief  年+1，若新的月份天数减少，没有这天，则转到这个月的最后一天
  * @retval *this 可用于链式编程
  */
Date& Date::toNextYear() {
    _year++;
    if (!isValid(_year, _month, _day))_day = getDays();
    return *this;
}
/**
  * @brief  年-1，若新的月份天数减少，没有这天，则转到这个月的最后一天
  * @retval *this 可用于链式编程
  */
Date& Date::toPreviousYear() {
    _year--;
    if (!isValid(_year, _month, _day))_day = getDays();
    return *this;
}
/**
  * @brief  重载前置自增运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator++(){
  return toNextDay();
  }
/**
  * @brief  重载前置自减运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator--(){
  return toPreviousDay();
}
/**
  * @brief  重载后置自增运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator++(int){
  return toNextDay();
}
/**
  * @brief  重载后置自减运算符
  * @retval *this 可用于链式编程
  */
Date& Date::operator--(int){
  return toPreviousDay();
}
Date Date::getNextDay()const {
    return Date(*this)++;
}
Date Date::getPreviousDay()const {
    return Date(*this)--;
}

Date Date::getNextMonth()const {
    return Date(*this).toNextMonth();
}
Date Date::getPreviousMonth()const {
    return Date(*this).toPreviousMonth();
}

Date Date::getNextYear()const {
    return Date(*this).toNextYear();
}
Date Date::getPreviousYear()const {
    return Date(*this).toPreviousYear();
}


/**
  * @brief  日期往后n天
  * @param  n 日期往后n天，可以是负数
  * @retval *this 可用于链式编程
  */
Date& Date::addDay(int n) {
    // This is a temp solution.
    // Todo: 优化时间复杂度
    if (n == 0)return *this;
    if (n > 0)for (int i = 0; i < n; i++)(*this)++;
    if (n < 0)for (int i = 0; i < -n; i++)(*this)--;
    return *this;
}
/**
  * @brief  日期往前n天
  * @param  n 日期往前n天，可以是负数
  * @retval *this 可用于链式编程
  */
Date& Date::subDay(int n) {
    // This is a temp solution.
    // Todo: 优化时间复杂度
    if (n == 0)return *this;
    if (n > 0)for (int i = 0; i < n; i++)(*this)--;
    if (n < 0)for (int i = 0; i < -n; i++)(*this)++;
    return *this;
}
/**
  * @brief  月份往后n月
  * @param  n 月份往后n月，可以是负数
  * @retval *this 可用于链式编程
  */
Date& Date::addMonth(int n) {
    // This is a temp solution.
    // Todo: 优化时间复杂度
    if (n == 0)return *this;
    if (n > 0)for (int i = 0; i < n; i++)(*this).toNextMonth();
    if (n < 0)for (int i = 0; i < -n; i++)(*this).toPreviousMonth();
    return *this;
}
/**
  * @brief  月份往前n月
  * @param  n 月份往前n月，可以是负数
  * @retval *this 可用于链式编程
  */
Date& Date::subMonth(int n) {
    // This is a temp solution.
    // Todo: 优化时间复杂度
    if (n == 0)return *this;
    if (n > 0)for (int i = 0; i < n; i++)(*this).toPreviousMonth();
    if (n < 0)for (int i = 0; i < -n; i++)(*this).toNextMonth();
    return *this;
}
/**
  * @brief  年往后n年
  * @param  n 年往后n年，可以是负数
  * @retval *this 可用于链式编程
  */
Date& Date::addYear(int n) {
    // This is a temp solution.
    // Todo: 优化时间复杂度
    if (n == 0)return *this;
    if (n > 0)for (int i = 0; i < n; i++)(*this).toNextYear();
    if (n < 0)for (int i = 0; i < -n; i++)(*this).toPreviousYear();
    return *this;
}
/**
  * @brief  年往前n年
  * @param  n 年往前n年，可以是负数
  * @retval *this 可用于链式编程
  */
Date& Date::subYear(int n) {
    // This is a temp solution.
    // Todo: 优化时间复杂度
    if (n == 0)return *this;
    if (n > 0)for (int i = 0; i < n; i++)(*this).toPreviousYear();
    if (n < 0)for (int i = 0; i < -n; i++)(*this).toNextYear();
    return *this;
}
Date& Date::operator+=(int n){
    return this->addDay(n);
}
Date& Date::operator-=(int n){
    return this->subDay(n);
}

Date Date::operator+(int n)const{
    if(n==0)return Date(*this);
    Date temp = Date(*this);
    if(n>0)for(int i = 0 ; i < n ; i++)temp++;
    if(n<0)for(int i = 0 ; i < -n ; i++)temp--;
    return temp;
}
//Date Date::operator-(int n)const {
//    if (n == 0)return Date(*this);
//    Date temp = Date(*this);
//    if (n > 0)for (int i = 0; i < n; i++)temp--;
//    if (n < 0)for (int i = 0; i < -n; i++)temp++;
//    return temp;
//}
bool Date::operator==(const Date& date)const{
    if(_day != date.getDay())return 0;
    if(_month != date.getMonth())return 0;
    if(_year != date.getYear())return 0;
    return 1;
}
bool Date::operator<(const Date& date)const{
    if(_year < date.getYear())return 1;
    else if(_month < date.getMonth())return 1;
    else if(_day < date.getDay())return 1;
    return 0;
    }
bool Date::operator<=(const Date& date)const{
    if(_year > date.getYear())return 0;
    else if(_month > date.getMonth())return 0;
    else if(_day > date.getDay())return 0;
    return 1;
    }

bool Date::operator!=(const Date& date)const{
    return !(*this==date);
    }
bool Date::operator>(const Date& date)const{
    return !(*this<date);
    }
bool Date::operator>=(const Date& date)const{
    return !(*this<=date);
    }



/**
 * @brief  算增量，末减前
 * @param  date1 初始
 * @param  date2 目标
 * @retval 增量
 */
int Date::diff(Date date1,Date date2){
    // 差得多时计算速度就比较灾难
    // todo: 优化时间复杂度
    if(date1 == date2)return 0;
    int cnt = 0;
    if(date1 > date2){
        while(date1 != date2){
            cnt++;
            date2++;
        }
        return -cnt;
    }
    //if(date1 < date2){
        while(date1 != date2){
            cnt++;
            date1++;
        }
        return cnt;
    //}
}
/**
 * @brief  返回离目标日期还差多少天
 * @param  date 目标日期
 * @retval 返回还差多少天
 */
int Date::diff(const Date& date){
    return diff(*this,date);
}

//int Date::operator-(const Date& date)const
//{
//    return diff(date, *this);
//}

Year Date::getYear()const{return _year;}
Month Date::getMonth()const{return _month;}
Day Date::getDay()const{return _day;}

void Date::set_date_output_callback(_date_output_callback_t _date_output_callback)
{
    this->_date_output_callback = _date_output_callback;
}
void Date::set_info_output_callback(_info_output_callback_t _info_output_callback)
{
    this->_info_output_callback = _info_output_callback;
}

/**
  * @brief  信息输出的默认回调函数
  * @param  s 字符串
  * @retval void
  */
void _defaultOutput(std::string s){
    std::cout << s << std::endl;
}
/**
  * @brief  日期输出的默认回调函数
  * @param  year  年份
  * @param  month 月份
  * @param  day   日期
  * @retval void
  */
void _defaultOutput(int year,int month,int day){    
  // 这里将uint8_t隐式类型转换成int，避免被认为是char
    std::cout << year << " " << month << " " << day << " " << std::endl;

}
/**
  * @brief  展示当前日期
  * @retval void
  */
void Date::showDate(){
        _date_output_callback(_year,_month,_day);
        }


Date::Date(Year year,Month month,Day day,
    _info_output_callback_t _info_output_callback,
    _date_output_callback_t _date_output_callback
):_info_output_callback(_info_output_callback),
_date_output_callback(_date_output_callback)
{
    setDate(year,month,day);
}

Date::~Date(){
    // 空实现
}

/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
