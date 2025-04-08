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
            std::string model_name = line.substr(line.find(":") + 2);
            std::cout << "CPU Model: " << model_name << std::endl;
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
    std::getline(stat_file, line); // Läs första raden (CPU-tider)
    std::istringstream iss(line);

    std::string cpu;
    long user, nice, system, idle;
    iss >> cpu >> user >> nice >> system >> idle;

    long total = user + nice + system + idle;
    long usage = total - idle;

    std::cout << "CPU Usage: " << (usage * 100 / total) << "%" << std::endl;

    stat_file.close();
}
void CPUProfiler::GetCPUTemperature()
{
    std::ifstream temp_file("/sys/class/thermal/thermal_zone0/temp");
    if (!temp_file.is_open())
    {
        std::cerr << "Failed to open /sys/class/thermal/thermal_zone0/temp" << std::endl;
        return;
    }

    int temp_millidegrees;
    temp_file >> temp_millidegrees;

    std::cout << "CPU Temperature: " << (temp_millidegrees / 1000.0) << "°C" << std::endl;

    temp_file.close();
}
void CPUProfiler::GetCPUArchitecture()
{
    std::string architecture = "";
    std::ifstream cpuinfo_file("/proc/cpuinfo");
    if (!cpuinfo_file.is_open())
    {
        std::cerr << "Failed to open /proc/cpuinfo" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(cpuinfo_file, line))
    {
        if (line.find("Architecture") != std::string::npos)
        {
            architecture = line.substr(line.find(":") + 2);
            break;
        }
    }

    std::cout << "CPU Architecture: " << architecture << std::endl;
    cpuinfo_file.close();
}
void CPUProfiler::GetCPUModel()
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
            std::string model_name = line.substr(line.find(":") + 2);
            std::cout << "CPU Model: " << model_name << std::endl;
            break;
        }
    }

    cpuinfo_file.close();
}
void CPUProfiler::GetCPUCores()
{
    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "CPU Cores: " << cores << std::endl;
}
void CPUProfiler::PrintCPUInfo()
{
    GetCPUInfo();
    GetCPUUsage();
    GetCPUTemperature();
    GetCPUArchitecture();
    GetCPUModel();
    GetCPUCores();
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
        std::cout << line << std::endl; // Skriv ut all minnesinformation
    }

    meminfo_file.close();
}

void MemoryProfiler::GetMemoryUsage()
{
    std::ifstream meminfo_file("/proc/meminfo");
    if (!meminfo_file.is_open())
    {
        std::cerr << "Failed to open /proc/meminfo" << std::endl;
        return;
    }

    long total_memory = 0;
    long free_memory = 0;
    std::string line;

    while (std::getline(meminfo_file, line))
    {
        if (line.find("MemTotal") != std::string::npos)
        {
            total_memory = std::stol(line.substr(line.find(":") + 1));
        }
        else if (line.find("MemFree") != std::string::npos)
        {
            free_memory = std::stol(line.substr(line.find(":") + 1));
        }

        if (total_memory > 0 && free_memory > 0)
        {
            break;
        }
    }

    long used_memory = total_memory - free_memory;
    std::cout << "Memory Usage: " << used_memory << " kB" << std::endl;

    meminfo_file.close();
}

void MemoryProfiler::GetMemorySize(MemoryUnit unit)
{
    std::ifstream meminfo_file("/proc/meminfo");
    if (!meminfo_file.is_open())
    {
        std::cerr << "Failed to open /proc/meminfo" << std::endl;
        return;
    }

    long total_memory = 0;
    std::string line;

    while (std::getline(meminfo_file, line))
    {
        if (line.find("MemTotal") != std::string::npos)
        {
            total_memory = std::stol(line.substr(line.find(":") + 1));
            break;
        }
    }

    meminfo_file.close();

    switch (unit)
    {
    case MemoryUnit::BYTE:
        std::cout << "Total Memory: " << total_memory * 1024 << " Bytes" << std::endl;
        break;
    case MemoryUnit::KILOBYTE:
        std::cout << "Total Memory: " << total_memory << " KB" << std::endl;
        break;
    case MemoryUnit::MEGABYTE:
        std::cout << "Total Memory: " << total_memory / 1024 << " MB" << std::endl;
        break;
    case MemoryUnit::GIGABYTE:
        std::cout << "Total Memory: " << total_memory / (1024 * 1024) << " GB" << std::endl;
        break;
    default:
        std::cerr << "Unsupported memory unit!" << std::endl;
        break;
    }
}

void MemoryProfiler::PrintMemoryInfo()
{
    GetMemoryInfo();
    GetMemoryUsage();
}

void DiskProfiler::GetDiskUsage()
{
    std::ifstream df_output("df -h");
    if (!df_output.is_open())
    {
        std::cerr << "Failed to retrieve disk usage information." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(df_output, line))
    {
        std::cout << line << std::endl; // Skriv ut diskanvändning
    }

    df_output.close();
}
void DiskProfiler::GetDiskSize(MemoryUnit unit)
{
    std::ifstream df_output("df -B1");
    if (!df_output.is_open())
    {
        std::cerr << "Failed to retrieve disk size information." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(df_output, line))
    {
        // Här kan du implementera logik för att extrahera storlek från df-utdata
    }

    df_output.close();
}
void DiskProfiler::GetDiskFreeSpace(MemoryUnit unit)
{
    struct statvfs stat;
    if (statvfs("/", &stat) != 0)
    {
        std::cerr << "Failed to retrieve disk free space information." << std::endl;
        return;
    }

    long free_space = stat.f_bavail * stat.f_frsize;

    switch (unit)
    {
    case MemoryUnit::BYTE:
        std::cout << "Free Disk Space: " << free_space << " Bytes" << std::endl;
        break;
    case MemoryUnit::KILOBYTE:
        std::cout << "Free Disk Space: " << free_space / 1024 << " KB" << std::endl;
        break;
    case MemoryUnit::MEGABYTE:
        std::cout << "Free Disk Space: " << free_space / (1024 * 1024) << " MB" << std::endl;
        break;
    case MemoryUnit::GIGABYTE:
        std::cout << "Free Disk Space: " << free_space / (1024 * 1024 * 1024) << " GB" << std::endl;
        break;
    default:
        std::cerr << "Unsupported memory unit!" << std::endl;
        break;
    }
}

void DiskProfiler::GetDiskUsedSpace(MemoryUnit unit)
{
    struct statvfs stat;
    if (statvfs("/", &stat) != 0)
    {
        std::cerr << "Failed to retrieve disk used space information." << std::endl;
        return;
    }

    long total_space = stat.f_blocks * stat.f_frsize;
    long free_space = stat.f_bavail * stat.f_frsize;
    long used_space = total_space - free_space;

    switch (unit)
    {
    case MemoryUnit::BYTE:
        std::cout << "Used Disk Space: " << used_space << " Bytes" << std::endl;
        break;
    case MemoryUnit::KILOBYTE:
        std::cout << "Used Disk Space: " << used_space / 1024 << " KB" << std::endl;
        break;
    case MemoryUnit::MEGABYTE:
        std::cout << "Used Disk Space: " << used_space / (1024 * 1024) << " MB" << std::endl;
        break;
    case MemoryUnit::GIGABYTE:
        std::cout << "Used Disk Space: " << used_space / (1024 * 1024 * 1024) << " GB" << std::endl;
        break;
    default:
        std::cerr << "Unsupported memory unit!" << std::endl;
        break;
    }
}

void DiskProfiler::PrintDiskInfo()
{
    GetDiskInfo();
    GetDiskUsage();
    GetDiskFreeSpace(MemoryUnit::GIGABYTE);
    GetDiskUsedSpace(MemoryUnit::GIGABYTE);
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