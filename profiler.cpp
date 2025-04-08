#include "profiler.hpp"

TimeProfiler::TimeProfiler()
{
    time = std::make_unique<Time>();
    currentTime = time->GetCurrentTime().tm_sec;
    currentDate = time->GetCurrentDate().tm_mday;
    currentDateTime = time->GetCurrentDateTime().tm_sec;
    startTime = 0;
    endTime = 0;
    elapsedTime = 0;
    TimeProfiler::RunTimer();

}
/*  
    Destructor implementation
    - Clean up resources if needed
    - The unique_ptr will automatically clean up its resource
*/
TimeProfiler::~TimeProfiler()
{
    
}

void TimeProfiler::RunTimer()
{
    startTime = time->GetCurrentTime().tm_sec;
    endTime = time->GetCurrentTime().tm_sec;
    elapsedTime = endTime - startTime;
}

void TimeProfiler::PrintTimerInfo()
{
    elapsedTime = endTime - startTime;
    std::cout << "Time Since Timer Started: " << elapsedTime << std::endl;
}


void CPUProfiler::GetCPUInfo()
{
    // Implementation to get CPU information
}
void CPUProfiler::GetCPUUsage()
{
    // Implementation to get CPU usage
}
void CPUProfiler::GetCPUTemperature()
{
    // Implementation to get CPU temperature
}
void CPUProfiler::GetCPUArchitecture()
{
    // Implementation to get CPU architecture
}
void CPUProfiler::GetCPUModel()
{
    // Implementation to get CPU model
}
void CPUProfiler::GetCPUCores()
{
    // Implementation to get CPU cores
}
CPUProfiler::CPUProfiler()
{
    // Constructor implementation
    GetCPUInfo();
    GetCPUUsage();
    GetCPUTemperature();
    GetCPUArchitecture();
    GetCPUModel();
    GetCPUCores();
}
/* 
    Destructor implementation
    - Clean up resources if needed
    - The unique_ptr will automatically clean up its resource
*/
CPUProfiler::~CPUProfiler()
{
    
}
Profiler::Profiler()
{
    cpu_profiler = std::make_unique<CPUProfiler>();
    memory_profiler = std::make_unique<MemoryProfiler>();
    disk_profiler = std::make_unique<DiskProfiler>();
    time_profiler = std::make_unique<TimeProfiler>();
}

/* 
    Destructor implementation
    - Clean up resources if needed
    - The unique_ptrs will automatically clean up their resources
*/
Profiler::~Profiler()
{
    
}