#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include "/usr/include/x86_64-linux-gnu/sys/statvfs.h"
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
    CPUProfiler();
    ~CPUProfiler();
    void GetCPUInfo();
    void GetCPUUsage();
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
    void GetMemorySize(MemoryUnit unit);
    void PrintMemoryInfo();
};

class DiskProfiler
{
public:
    DiskProfiler();
    ~DiskProfiler();
    void GetDiskInfo();
    void GetDiskUsage();
    void GetDiskFreeSpace(MemoryUnit unit);
    void GetDiskUsedSpace(MemoryUnit unit);
    void PrintDiskInfo();
};

class TimeProfiler
{
public:
    TimeProfiler();
    ~TimeProfiler();
    void StartTimer();
    void PrintTimerInfo();

private:
    std::unique_ptr<Time> time;
    int startTime;
    int endTime;
};

class Profiler
{
public:
    Profiler();
    ~Profiler();

    std::unique_ptr<CPUProfiler> cpu_profiler;
    std::unique_ptr<MemoryProfiler> memory_profiler;
    std::unique_ptr<DiskProfiler> disk_profiler;
    std::unique_ptr<TimeProfiler> time_profiler;
};