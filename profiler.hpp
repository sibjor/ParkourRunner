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

enum class TimeUnit
{
    NANOSECOND,
    MICROSECOND,
    MILLISECOND,
    SECOND,
    MINUTE,
    HOUR,
};

class CPUProfiler
{
public:
    CPUProfiler();
    ~CPUProfiler();
    void GetCPUInfo();
    void GetCPUUsage();
    void GetCPUFrequency();
    void GetCPUTemperature();
    void GetCPUArchitecture();
    void GetCPUModel();
    void GetCPUCores();
    void PrintCPUInfo();
};
class MemoryProfiler
{
public:
    MemoryProfiler();
    ~MemoryProfiler();
    void GetMemoryInfo();
    void GetMemoryUsage();
    void GetMemorySpeed();
    void GetMemoryType();
    void GetMemorySize(MemoryUnit unit);
    void GetMemoryFreeSpace(MemoryUnit unit);
    void GetMemoryUsedSpace(MemoryUnit unit);
    void PrintMemoryInfo();
    
};
class DiskProfiler
{
public:
    DiskProfiler();
    ~DiskProfiler();
    void GetDiskInfo();
    void GetDiskUsage();
    void GetDiskSpeed();
    void GetDiskType();
    void GetDiskSize(MemoryUnit unit);
    void GetDiskFreeSpace(MemoryUnit unit);
    void GetDiskUsedSpace(MemoryUnit unit);
    void PrintDiskInfo();

    
};
class TimeProfiler
{
public:
    TimeProfiler();
    ~TimeProfiler();

    void GetCurrentTime();
    void GetCurrentDate();
    void GetCurrentDateTime();
    void StartTimer();
    void StopTimer();
    void GetElapsedTime(TimeUnit unit);
    void RunTimer();
    void PrintTimerInfo();
    
private:
    std::unique_ptr<Time> time;
    int currentTime;
    int currentDate;
    int currentDateTime;
    int startTime;
    int endTime;
    int elapsedTime;
    
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