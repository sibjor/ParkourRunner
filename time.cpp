#include "time.hpp"

Time::Time()
{
    current_time = new std::tm;

    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    *current_time = *std::localtime(&now_c);
}

Time::~Time()
{
    delete current_time;
}

std::tm Time::GetCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&now_c);

    local_time.tm_year = 0;
    local_time.tm_mon = 0;
    local_time.tm_mday = 0;

    return local_time;
}

std::tm Time::GetCurrentTime(TimeZone zone)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    if (zone == TimeZone::UTC)
    {
        return *std::gmtime(&now_c);
    }
    else if (zone == TimeZone::LOCAL)
    {
        return *std::localtime(&now_c);
    }
    else
    {
        throw std::invalid_argument("Custom time zones are not implemented.");
    }
}

std::tm Time::GetCurrentDate()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&now_c);

    local_time.tm_hour = 0;
    local_time.tm_min = 0;
    local_time.tm_sec = 0;

    return local_time;
}

std::tm Time::GetCurrentDateTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    return *std::localtime(&now_c);
}

std::tm Time::GetCurrentDateTime(TimeZone zone)
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    if (zone == TimeZone::UTC)
    {
        return *std::gmtime(&now_c);
    }
    else if (zone == TimeZone::LOCAL)
    {
        return *std::localtime(&now_c);
    }
    else
    {
        throw std::invalid_argument("Custom time zones are not implemented.");
    }
}