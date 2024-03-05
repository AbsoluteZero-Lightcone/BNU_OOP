#include "date.h"
#include <cstdint>
#include <string>
// private:
bool Date::_isLeapYear(Year year){
    if(year % 100 == 0){
        if(year % 400 == 0)return 1;
        return 0;
    }
    else if(year % 4 == 0)return 1;
    return 0;
}
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
Day Date::_getDays(){
    if( _month == 2 ){
        if(_isLeapYear(_year)) return 29;
        return 28;
    }
    else if(_is31Days(_month))return 31;
    return 30;
}bool Date::_isLeapYear(){
    if(_year % 100 == 0){
        if(_year % 400 == 0)return 1;
        return 0;
    }
    else if(_year % 4 == 0)return 1;
    return 0;
}
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
Day Date::_getDays(Year year,Month month){
    if( month == 2 ){
        if(_isLeapYear(year)) return 29;
        return 28;
    }
    else if(_is31Days(month))return 31;
    return 30;
}

bool Date::_isValid(Year year,Month month,Day day){
    if( year == 0 )return 0;
    if( month > 12 || month < 1 )return 0;
    if( day > _getDays(year,month) || day < 1 )return 0;
}

// public:
void Date::setDate(Year year,Month month,Day day){
    if(!_isValid(year,month,day)){
        info_output_interface_callback_handler("Invalid Date");
        return;
    }
    _year = year;
    _month = month;
    _day = day;
}

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
Date& Date::addDay(uint8_t n){
    // This is a temp solution.
    // Todo: remove loops
    for(uint8_t i = 0 ; i < n ; i++)(*this)++;
    return *this;
}
Date& Date::subDay(uint8_t n){
    // This is a temp solution.
    // Todo: remove loops
    for(uint8_t i = 0 ; i < n ; i++)(*this)--;
    return *this;
}

inline Year Date::getYear(){return _year;}
inline Month Date::getMonth(){return _month;}
inline Day Date::getDay(){return _day;}

inline void Date::showDate(){date_output_interface_callback_handler(_year,_month,_day);}

inline Date::Date():_year(2024),_month(1),_day(1){}
inline Date::Date(Year year,Month month,Day day){
    setDate(year,month,day);
}
inline Date::~Date(){}

