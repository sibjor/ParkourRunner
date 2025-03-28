/* Utilities
    Here follows declarations of
    stuff that makes life easier
    and more comfortable!
    Content such as:
    - filesystem utilities
    - ... more to come?
    */

#include "central.hpp"

class Utility{
    public:
        // Constructor
        Utility();

        // Destructor
        ~Utility();

        // Function to check if a file exists
        bool FileExists(const std::string &path);

        // Function to get the current time as a string
        std::string GetCurrentTimeString();
}