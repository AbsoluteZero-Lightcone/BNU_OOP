#pragma once
#include <iostream>
#include <cstdint>
using namespace std;

typedef int16_t Year;
typedef uint8_t Month;
typedef uint8_t Day;

class Date{
    private:
    Year _year;
    Month _month;
    Day _day;
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
    bool _isValid(Year year,Month month,Day day){
        if( year == 0 )return 0;
        if( month > 12 || month < 1 )return 0;
        if(month == 2){
            if(_isLeapYear(year)){
                if(day>29 || day<1)return 0;
                return 1;
            }else{
                if(day>28 || day<1)return 0;
                return 1;
            }
        }else{
            if()
        }
    }
    public:
    Date(Year year,Month month,Day day){
        
    }
    
};