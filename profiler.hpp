#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "time.hpp"

enum class MemoryUnit
{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
};

class CPUProfiler
{
public:

    
};
class MemoryProfiler
{
public:

    
};
class DiskProfiler
{
public:

    
};
class TimeProfiler
{
public:
    TimeProfiler();
    ~TimeProfiler();
    
private:
    std::unique_ptr<Time> time;
    
};

class Profiler
{
public:
    Profiler();
    ~Profiler();
    
private:
    std::unique_ptr<CPUProfiler> cpu_profiler;
    std::unique_ptr<MemoryProfiler> memory_profiler;
    std::unique_ptr<DiskProfiler> disk_profiler;
    std::unique_ptr<TimeProfiler> time_profiler;
};