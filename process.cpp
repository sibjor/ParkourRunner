#include "process.hpp"

using process_index = std::unique_ptr<std::vector<std::unique_ptr<Process>>>;

Process::Process(const char* name_of_host, const char* name_of_self, const u_int* id)
{
    if(!name_of_host && !name_of_self)
    {
        std::cerr << "Error: Invalid parameters passed to Process constructor. Self destructs" << std::endl;
        this->~Process();
        return;
    }
    else if (!id)
    {
        this->id = GenerateID();
        return;
    }

    this->host = name_of_host;
    this->name = name_of_self;

    if(!has_parent)
    {
        this->role = LegacyRole::ROOT;
    }
    else
    {
        this->role = LegacyRole::CHILD;
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

