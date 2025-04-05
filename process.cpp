#include "process.hpp"

using process_index = std::unique_ptr<std::vector<std::unique_ptr<Process>>>;

Process::Process(const char* name_of_host, const char* name_of_self, const u_int* id)
{
    if(!name_of_host && !name_of_self)
    {
        std::cerr << "Error: Invalid parameters passed to Process constructor." << std::endl;
        this->~Process();
        return;
    }
}
/* 
    Destructor implementation
    Clean up resources if needed
    The unique_ptr will automatically clean up its resource
*/
Process::~Process()
{
    
}

process_index &Process::ReturnIndex()
{
    return index;
}

Status Process::ReturnStatus()
{
    return status;
}

const u_int *Process::GenerateID()
{
    return id;
}

