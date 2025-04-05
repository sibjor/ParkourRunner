#include "data.hpp"

FileManager::FileManager()
{
    if (!std::filesystem::exists("data"))
    {
        this->data_dir = "data";
        std::filesystem::create_directory(data_dir);
    }
}
FileManager::~FileManager()
{
}
void FileManager::SetName(const std::string &name)
{
    this->data_dir = name;
}
std::string FileManager::GetName()
{
    return data_dir.string();
}
std::string FileManager::ReadFile(const std::filesystem::path path)
{
    if (!std::filesystem::exists(path))
    {
        throw std::runtime_error("File does not exist: " + path.string());
    }

    std::ifstream file(path);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file: " + path.string());
    }

    this->buffer << file.rdbuf();
    file.close();

    return this->buffer.str();
}
void FileManager::WriteFile(const std::filesystem::path path, const std::string &data)
{
        std::ofstream file(path);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file: " + path.string());
        }
        file << data;
        file.close();
}
