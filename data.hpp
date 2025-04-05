#pragma once

#include <sstream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <iostream>

class FileManager
{
public:
    FileManager();
    ~FileManager();
    void SetName(const std::string &name);
    std::string GetName();
    std::string ReadFile(const std::filesystem::path path);
    void WriteFile(const std::filesystem::path path, const std::string &data);

private:
    std::filesystem::path data_dir;
    std::ostringstream buffer;
};