#pragma once

#include <vector>
#include <random>
#include <memory>

enum class ProcessStatus : int
{
    PENDING,
    ACTIVE,
    INACTIVE,
    COMPLETED,
    TERMINATED,
    ERROR,
};
class Process
{
public:
    Process();
    ~Process();

    ProcessStatus &InitProcess();
    ProcessStatus &GetProcessStatus();
    const std::string &GetProcessID();
    std::vector<std::unique_ptr<Process>> &GetChildProcesses(std::vector<std::unique_ptr<Process>> child_processes);
    /* Should
    - return all derived child processes starting from argument */
    std::vector<std::unique_ptr<Process>> &GetProcessLegacy(std::vector<std::unique_ptr<Process>> child_processes);
    /* Should
    - Call GetChildProcesses()
    - Display all child from scope of the argument in function stated above
    - Render a cool diagram or maybe tree model (when there is time)*/
    void DisplayProcessLegacy();

    ProcessStatus &KillProcess(Process *process);
    ProcessStatus &KillProcess(std::vector<std::unique_ptr<Process>> child_processes);
    ProcessStatus &KillProcess(std::vector<std::unique_ptr<Process>> child_processes, Process *process);

private:
    const char *process_id;
    int process_layer;

    ProcessStatus status;
    std::vector<std::unique_ptr<Process>> child_processes;

    ProcessStatus &GetProcessLayer();
    ProcessStatus &SetProcessStatus(ProcessStatus status);
    void SetProcessID();
};