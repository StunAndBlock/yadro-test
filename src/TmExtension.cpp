#include "TmExtension.hpp"


TimeEx::TimeEx(){
    tm_hour = 0;
    tm_min = 0;
    this->updateMin();
}


TimeEx::TimeEx(int hours, int mins){
    tm_hour = hours;
    tm_min = mins;
    this->updateMin();
}

TimeEx::TimeEx(struct std::tm src){
    tm_hour = src.tm_hour;
    tm_min = src.tm_min;
    this->updateMin();
}


void TimeEx::updateMin(){
    tm_total_min_ = this->tm_min + this ->tm_hour * 60u;
}


bool TimeEx::operator>(const TimeEx& rhs) const{
    return tm_total_min_ > rhs.tm_total_min_;
}

bool TimeEx::operator<(const TimeEx& rhs) const{
    return tm_total_min_ < rhs.tm_total_min_;
}

std::ostream& operator<<(std::ostream& os,const TimeEx& rhs) {
    struct std::tm tmstmp{0, rhs.tm_min, rhs.tm_hour};
    os << std::put_time(&tmstmp,"%H:%M");
    return os;
}