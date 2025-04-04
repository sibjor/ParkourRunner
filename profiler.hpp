#pragma once

#include <string>
#include <memory>
#include <iostream>

enum class MemoryUnit : int
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
};
class MemoryProfiler
{
public:
    MemoryProfiler();
    ~MemoryProfiler();
};
class DiskProfiler
{
public:
    DiskProfiler();
    ~DiskProfiler();
};
class TimeProfiler
{
public:
    TimeProfiler();
    ~TimeProfiler();
};

class Profiler
{
public:
    Profiler(const std::string *host_name);
    ~Profiler();
    void PrintProfilerInfo();
private:

private:
    std::unique_ptr<CPUProfiler> cpu_profiler;
    std::unique_ptr<MemoryProfiler> memory_profiler;
    std::unique_ptr<DiskProfiler> disk_profiler;
    std::unique_ptr<TimeProfiler> time_profiler;
};