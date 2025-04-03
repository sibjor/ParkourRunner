#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "time.hpp"

enum class Memory
{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
};

enum class CPU
{
    PERCENTAGE,
    CYCLES,
    CLOCK_SPEED,
};

enum class Disk
{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
};

class Profiler
{
public:
    Profiler();
    ~Profiler();

    void ProfilerComplete();
    void ProfilerTime();
};