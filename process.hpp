#pragma once

#include <vector>
#include <random>
#include <memory>
#include <thread>
#include <iostream>
#include <random>
#include <thread>
#include "time.hpp"
#include "profiler.hpp"
#include "data.hpp"

enum class Status
{
    SCHEDULED,    // More than 10 minutes
    PENDING,      // Less than 10 minutes
    INITIALIZING, // Defined first
    ACTIVE,       // Defined last
    INACTIVE,     // Defined last in destructor, messages the parent Process
    TERMINATED,
    ERROR,
};

enum class LegacyRole
{
    ROOT,
    CHILD,
    PARENT,
    SIBLING,
};

class Process : public Time, public Profiler, public FileManager
{

public:
    Process(const char *name_of_host, const char *name_of_self, const u_int *id);
    std::unique_ptr<std::vector<std::unique_ptr<Process>>> &ReturnIndex();
    Status ReturnStatus();

private:
    bool has_parent;
    const char *host;
    const char *name;
    const u_int *id;
    std::unique_ptr<std::vector<std::unique_ptr<Process>>> index;
    LegacyRole role;
    Status status;

    const u_int *GenerateID();
};
