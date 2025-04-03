#pragma once

#include <string>
#include <memory>
#include <iostream>
#include "process.hpp"

enum class Memory
{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
};

enum class CPU
{
    PERCENTAGE,
    CYCLES,
    CLOCK_SPEED,
};

enum class Disk
{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
    TERABYTE,
};