#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>

#include "process.hpp"

enum class Time
{
    NANOSECOND,
    MICROSECOND,
    MILLISECOND,
    SECOND,
    MINUTE,
    HOUR, 
};

enum class Date{

    DAY,
    MONTH,
    YEAR,
};