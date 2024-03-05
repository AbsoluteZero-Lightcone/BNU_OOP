/**
  ******************************************************************************
  * @file    date.h
  * @author  Zhang Yifa
  * @version V1.0.0
  * @date    2024-03-05
  * @brief   Abstract a class for handling date data.
  * @encode  UTF-8
  ******************************************************************************
  */
#pragma once
#include <cstdint>
#include <string>

typedef int16_t Year;
typedef uint8_t Month;
typedef uint8_t Day;

class Date{
private:
    Year _year;
    Month _month;
    Day _day;

    bool _isLeapYear(Year year);
    bool _is31Days(Month month);
    Day _getDays(Year year,Month month);

    bool _isLeapYear();
    bool _is31Days();
    Day _getDays();

    bool _isValid(Year year,Month month,Day day);

public:
    void (*info_output_interface_callback_handler)(std::string);
    void (*date_output_interface_callback_handler)(Year,Month,Day);

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

    Date();
    Date(Year year,Month month,Day day);
    ~Date();
    
};
/********* Zhang Yifa | Absolute Zero Studio - Lightcone *******END OF FILE****/
