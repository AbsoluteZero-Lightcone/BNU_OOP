/**
  ******************************************************************************
  * @file    date.h
  * @author  Zhang Yifa
  * @version V1.1.0
  * @date    2024-03-05
  * @brief   Abstract a class for handling date data.
  * @encode  UTF-8
  ******************************************************************************
  */
#pragma once
#include <iostream>
#include <cstdint>
#include <string>

typedef int16_t Year;
typedef uint8_t Month;
typedef uint8_t Day;

void _defaultOutput(std::string s){
    std::cout << s << std::endl;
}
void _defaultOutput(Year year,Month month,Day day){
    std::cout << year << "年" << month << "月" << day << "日" << std::endl;
}

class Date{
private:
    Year _year;
    Month _month;
    Day _day;
    
    typedef void (*_info_output_interface_callback_handler_t)(std::string);
    typedef void (*_date_output_interface_callback_handler_t)(Year,Month,Day);
    _info_output_interface_callback_handler_t _info_output_interface_callback_handler = _defaultOutput;
    _date_output_interface_callback_handler_t _date_output_interface_callback_handler = _defaultOutput;

    bool _isLeapYear(Year year);
    bool _is31Days(Month month);
    Day _getDays(Year year,Month month);

    bool _isLeapYear();
    bool _is31Days();
    Day _getDays();

    bool _isValid(Year year,Month month,Day day);


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

    Year getYear();
    Month getMonth();
    Day getDay();
    void showDate();
    void set_date_output_interface_callback_handler(_date_output_interface_callback_handler_t _date_output_interface_callback_handler){
        this->_date_output_interface_callback_handler = _date_output_interface_callback_handler;
    }
    void set_info_output_interface_callback_handler(_info_output_interface_callback_handler_t _info_output_interface_callback_handler){
        this->_info_output_interface_callback_handler = _info_output_interface_callback_handler;
    }

    Date();
    Date(Year year,Month month,Day day);
    ~Date();
    
};
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
