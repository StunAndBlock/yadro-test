#ifndef COREDATA_H
#define COREDATA_H

#include <chrono>
#include <ctime>
#include "UsefullIncludes.hpp"
#include "TmExtension.hpp"
using namespace std::chrono;
struct CoreData
{
    uint32_t tablesCount;
    TimeEx startTime;
    TimeEx endTime;
    uint32_t costPerHour;
    uint16_t events;
};






#endif /* COREDATA_H */