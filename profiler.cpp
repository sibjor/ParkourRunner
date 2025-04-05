#include "profiler.hpp"

TimeProfiler::TimeProfiler()
{
    time = std::make_unique<Time>();
}
/*  
    Destructor implementation
    - Clean up resources if needed
    - The unique_ptr will automatically clean up its resource
*/
TimeProfiler::~TimeProfiler()
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