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
    bool _isValid(Year year,Month month,Day day);
public:
    void (*info_output_interface_callback_handler)(string);
    void (*date_output_interface_callback_handler)(Year,Month,Day);
    void setDate(Year year,Month month,Day day);
    Year getYear();
    Month getMonth();
    Day getDay();
    void showDate();
};