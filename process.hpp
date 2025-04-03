#pragma once

// C++ Standard libraries
#include <vector>
#include <random>
#include <memory>

enum class BoolEnum
{
    TRUE,
    FALSE,
};

/* HERE FOLLOWS PROCESS DEFENITIONS */

enum class ProcessFunctionEnum
{
    LOG,
    SELECT,
    READ,
    PARSE,
    WRITE,
    ERROR,

    SPAWN,
    KILL,
};

enum class ProcessScenarioEnum
{
    IMPOSSIBLE,
    POSSIBLE,
};

enum class ProcessRankEnum
{
    ROOT,
    PARENT,
    CHILD,
    SIBLING,
};

/* HERE FOLLOWS PROCESS STATUS*/

enum class ProcessStatusEnum
{
    INITIALIZED,
    PENDING,
    RUNNING,
    STOPPED,
    PAUSED,
    TERMINATED,
    ERROR,
};

enum class ProcessPositionEnum
{
    MAIN_THREAD,
    MAIN_LOOP,

    PARENT_POSITION,
    CHILD_POSITION,
    SIBLING_POSITION,
    SELF_POSITION,

    LAYER_SELF,
    LAYER_PARENT,
    LAYER_CHILD,
    LAYER_SIBLING,
};

class Process
{

public:
    /* Constructor
    - initializes a vector to hold processes */
    Process(std::string name)
    {
        ListenToOrder();
        Profiler();
    };
    ~Process();

    void InitializeProcess(std::string name);
    void DeleteProcess(std::string name);
    void ListenToOrder();
    void Profiler();

    // Getters and Setters
    std::vector<std::unique_ptr<Process *>> *GetProcessList(std::string name) const;
    ProcessFunctionEnum GetFunction(std::string name) const;
    ProcessScenarioEnum GetScenario(std::string name) const;
    ProcessRankEnum GetRank(std::string name) const;
    ProcessStatusEnum GetStatus(std::string name) const;
    ProcessPositionEnum GetPosition(std::string name) const;

    void SetFunction(ProcessFunctionEnum function, std::string name);
    void SetScenario(ProcessScenarioEnum scenario, std::string name);
    void SetRank(ProcessRankEnum rank, std::string name);
    void SetStatus(ProcessStatusEnum status, std::string name);
    void SetPosition(ProcessPositionEnum position, std::string name);
    void SetProcessID();

private:
    ProcessFunctionEnum process_function;
    ProcessScenarioEnum process_scenario;
    ProcessRankEnum process_rank;
    ProcessStatusEnum process_status;
    ProcessPositionEnum process_position;
    std::vector<std::unique_ptr<Process>> process_list;
    std::vector<std::unique_ptr<Process *>> *process_list;
    std::string process_name;
    std::string process_id;
    std::string process_status;
    std::string process_position;
    std::string process_type;
    std::string process_description;
    std::string process_time;
    std::string process_date;
    std::string process_memory;
    std::string process_cpu;
    std::string process_disk;
};
;