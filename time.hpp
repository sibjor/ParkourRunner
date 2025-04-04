/*
    https://cplusplus.com/reference/ctime/
*/

#pragma once

#include <ctime>
#include <iostream>

enum class TimeEnum : int
{
    MILLISECOND,
    SECOND,
    MINUTE,
    HOUR,
};
enum class DateEnum : int
{
    DAY,
    MONTH,
    YEAR,
};
enum class DateTimeEnum : int
{
    DDMMYYYY,
    MMDDYYYY,
    YYYYMMDD,

    DDMMYYYYHHMM,
    MMDDYYYYHHMM,
    YYYYMMDDHHMM,
};
