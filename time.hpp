/*
    https://cplusplus.com/reference/ctime/
*/

#pragma once

#include <ctime>
#include <chrono>
#include <iostream>

enum class TimeUnit
{
    NANOSECOND,
    MICROSECOND,
    MILLISECOND,
    SECOND,
    MINUTE,
    HOUR,

    TICKS,
};
enum class DateUnit
{
    DAY,
    MONTH,
    YEAR,
};

enum class TimeZone
{
    UTC,
    LOCAL,
    CUSTOM,
};

class Time 
{
public:
    Time();
    ~Time();
    std::tm GetCurrentTime();
    std::tm GetCurrentTime(TimeZone zone);
    std::tm GetCurrentDate();
    std::tm GetCurrentDateTime();
    std::tm GetCurrentDateTime(TimeZone zone);

private:
    std::tm *current_time;
    std::tm *current_date;
    std::tm *current_date_time;
};