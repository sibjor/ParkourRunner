#include "profiler.hpp"

// TimeProfiler Implementation
TimeProfiler::TimeProfiler() : time(std::make_unique<Time>()), startTime(0), endTime(0) {}

TimeProfiler::~TimeProfiler() {}

void TimeProfiler::StartTimer()
{
    startTime = time->GetCurrentTime().tm_sec;
    std::cout << "Timer started at: " << startTime << " seconds" << std::endl;
}

void TimeProfiler::PrintTimerInfo()
{
    endTime = time->GetCurrentTime().tm_sec;
    int elapsedTime = endTime - startTime;
    std::cout << "Time Since Timer Started: " << elapsedTime << " seconds" << std::endl;
}

// CPUProfiler Implementation
CPUProfiler::CPUProfiler() {}

CPUProfiler::~CPUProfiler() {}

void CPUProfiler::GetCPUInfo()
{
    std::ifstream cpuinfo_file("/proc/cpuinfo");
    if (!cpuinfo_file.is_open())
    {
        std::cerr << "Failed to open /proc/cpuinfo" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(cpuinfo_file, line))
    {
        if (line.find("model name") != std::string::npos)
        {
            std::cout << "CPU Model: " << line.substr(line.find(":") + 2) << std::endl;
            break;
        }
    }
    cpuinfo_file.close();
}

void CPUProfiler::GetCPUUsage()
{
    std::ifstream stat_file("/proc/stat");
    if (!stat_file.is_open())
    {
        std::cerr << "Failed to open /proc/stat" << std::endl;
        return;
    }

    std::string line;
    std::getline(stat_file, line);
    std::istringstream iss(line);

    std::string cpu;
    long user, nice, system, idle;
    iss >> cpu >> user >> nice >> system >> idle;

    long total = user + nice + system + idle;
    long usage = total - idle;

    std::cout << "CPU Usage: " << (usage * 100 / total) << "%" << std::endl;
    stat_file.close();
}

void CPUProfiler::PrintCPUInfo()
{
    GetCPUUsage();
    GetCPUInfo();
}

// MemoryProfiler Implementation
MemoryProfiler::MemoryProfiler() {}

MemoryProfiler::~MemoryProfiler() {}

void MemoryProfiler::GetMemoryInfo()
{
    std::ifstream meminfo_file("/proc/meminfo");
    if (!meminfo_file.is_open())
    {
        std::cerr << "Failed to open /proc/meminfo" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(meminfo_file, line))
    {
        std::cout << line << std::endl;
    }
    meminfo_file.close();
}

void MemoryProfiler::PrintMemoryInfo()
{
    GetMemoryInfo();
}

// DiskProfiler Implementation
DiskProfiler::DiskProfiler() {}

DiskProfiler::~DiskProfiler() {}

void DiskProfiler::GetDiskFreeSpace(MemoryUnit unit)
{
    struct statvfs stat;
    if (statvfs("/", &stat) != 0)
    {
        std::cerr << "Failed to retrieve disk free space information." << std::endl;
        return;
    }

    long free_space = stat.f_bavail * stat.f_frsize;
    std::cout << "Free Disk Space: " << free_space / (1024 * 1024) << " MB" << std::endl;
}

void DiskProfiler::PrintDiskInfo()
{
    GetDiskFreeSpace(MemoryUnit::MEGABYTE);
}

// Profiler Implementation
Profiler::Profiler()
{
    cpu_profiler = std::make_unique<CPUProfiler>();
    memory_profiler = std::make_unique<MemoryProfiler>();
    disk_profiler = std::make_unique<DiskProfiler>();
    time_profiler = std::make_unique<TimeProfiler>();
}

Profiler::~Profiler() {}