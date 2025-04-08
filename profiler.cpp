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

void TimeProfiler::ReturnTimer()
{
    elapsedTime = endTime - startTime;
    std::cout << "Time Since Timer Started: " << elapsedTime << std::endl;
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