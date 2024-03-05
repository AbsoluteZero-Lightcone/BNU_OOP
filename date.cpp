#include "date.h"
#include <cstdint>
#include <string>
// private:
    bool _isLeapYear(Year year){}
    bool _is31Days(Month month){
        if(month == 1)return 1;
        if(month == 3)return 1;
        if(month == 5)return 1;
        if(month == 7)return 1;
        if(month == 8)return 1;
        if(month == 10)return 1;
        if(month == 12)return 1;
        return 0;
    }
    Day _getDays(Year year,Month month){
        if( month == 2 ){
            if(_isLeapYear(year)) return 29;
            return 28;
        }
        else if(_is31Days(month))return 31;
        return 30;
    }
    bool _isValid(Year year,Month month,Day day){
        if( year == 0 )return 0;
        if( month > 12 || month < 1 )return 0;
        if( day > _getDays(year,month) || day < 1 )return 0;
    }
// public:
    void (*info_output_interface_callback_handler)(string);
    void (*date_output_interface_callback_handler)(Year,Month,Day);
    void setDate(Year year,Month month,Day day){
        if(!_isValid(year,month,day)){
            info_output_interface_callback_handler("Invalid Date");
            return;
        }
        _year = year;
        _month = month;
        _day = day;
    }
    Year getYear(){return _year;}
    Month getMonth(){return _month;}
    Day getDay(){return _day;}
    void showDate(){date_output_interface_callback_handler(_year,_month,_day);}
    Date():_year(2024),_month(1),_day(1){}
    Date(Year year,Month month,Day day){
        setDate(year,month,day);
    }
    ~Date(){}

