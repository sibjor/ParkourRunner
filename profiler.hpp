#pragma once

#include <string>
#include <memory>
#include <iostream>

enum class MemoryUnitEnum : int
{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
};

enum class StatusEnum : int
{
    PENDING,
    ACTIVE,
    INACTIVE,
    COMPLETED,
    ERROR,
    TERMINATED,
};

class RootProfiler
{
public:
    RootProfiler(const std::string* host_name);
    ~RootProfiler();

    /* Return the host name */
    const std::string* GetHostName() const;

    /* Return the status of the profiler */
    StatusEnum GetStatus() const;


private:
    const std::string* host_name;
    StatusEnum status;

    void SetStatus(StatusEnum status);
};

class CPUProfiler : RootProfiler
{
public:
    CPUProfiler();
    ~CPUProfiler();

    /* Return ticks since construction */
    unsigned long long GetTicks();
    void PrintTicks();
};
class MemoryProfiler : RootProfiler
{
public:
    MemoryProfiler();
    ~MemoryProfiler();

    /* Return memory usage in specified unit */
    unsigned long long GetMemoryUsage(MemoryUnitEnum unit);
    void PrintMemoryUsage(MemoryUnitEnum unit);
};
class DiskProfiler : RootProfiler
{
public:
    DiskProfiler();
    ~DiskProfiler();

    /* Return disk usage in specified unit */
    unsigned long long GetDiskUsage(MemoryUnitEnum unit);
    void PrintDiskUsage(MemoryUnitEnum unit);
};

/* This is the one to be implemented
- when constructed, spawns objects of different profilers stored in "smart pointers" 
- to use, just initialize an object of this class 
- pass a const reference when declaring the host_name argument */
class Profiler : CPUProfiler, MemoryProfiler, DiskProfiler
{
public:
    Profiler(const std::string* host_name);
    ~Profiler();
private:
    const std::string* host;
    const CPUProfiler cpu_profiler;
    const MemoryProfiler memory_profiler;
    const DiskProfiler disk_profiler;
};