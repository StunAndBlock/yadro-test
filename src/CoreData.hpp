#ifndef COREDATA_H
#define COREDATA_H

#include <chrono>
#include <ctime>
#include "Event.hpp"

struct CoreData
{
    uint32_t tablesCount;
    TimeEx startTime;
    TimeEx endTime;
    uint32_t costPerHour;
    uint16_t events;
};






#endif /* COREDATA_H */