#pragma once

#include <vector>
#include <random>
#include <memory>
#include <thread>

enum class Status : int
{
    SCHEDULED,    // More than 10 minutes
    PENDING,      // Less than 10 minutes
    INITIALIZING, // Defined first
    ACTIVE,       // Defined last
    INACTIVE,     // Defined last in destructor, messages the parent Process
    TERMINATED,
    ERROR,
};

enum class Type : int
{
    PROFILER,
    MAIN_PROGRAM,
    CHILD_PROGRAM,

};

enum class Result : int
{
    SUCCEDED,
    FAILED,
};

enum class FamilyRole : int
{
    ROOT,
    CHILD,
    PARENT,
    SIBLING,
};

class Process
{
    using Legacy = std::unique_ptr<std::vector<std::unique_ptr<Process>>>;

public:
    Process();
    Process(char *name, u_int id);
    Process(char *name_of_host, char *name, u_int id);
    ~Process();

    Legacy &ReturnLegacy();
    FamilyRole &ReturnFamilyRole();

private:
    char *name_of_host;
    char *name_of_self;
    u_int id;

    Legacy Legacy;
    FamilyRole FamilyRole;
    Time *time;
    
};

