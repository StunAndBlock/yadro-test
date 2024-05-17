#include "TmExtension.hpp"


TimeEx::TimeEx(){
    tm_hour = 0;
    tm_min = 0;
    tm_day = 0;
    this->updateTotalMin();
}

TimeEx::TimeEx(int hour, int min, int day){
    tm_hour = hour;
    tm_min = min;
    tm_day = day;
    this->updateTotalMin();
}

TimeEx::TimeEx(struct std::tm src){
    tm_hour = src.tm_hour;
    tm_min = src.tm_min;
    tm_day = src.tm_mday;
    this->updateTotalMin();
}

void TimeEx::makeNextDay(){
    this->tm_day = 1;
    this->updateTotalMin();
}

void TimeEx::updateTotalMin(){
    tm_total_min_ = this->tm_min + this ->tm_hour * 60u + this->tm_day * 24u * 60u;
}


bool TimeEx::operator>(const TimeEx& rhs) const{
    return tm_total_min_ > rhs.tm_total_min_;
}

bool TimeEx::operator>=(const TimeEx& rhs) const{
    return tm_total_min_ >= rhs.tm_total_min_;
}


bool TimeEx::operator<(const TimeEx& rhs) const{
    return tm_total_min_ < rhs.tm_total_min_;
}

std::ostream& operator<<(std::ostream& os,const TimeEx& rhs) {
    struct std::tm tmstmp{0, rhs.tm_min, rhs.tm_hour};
    os << std::put_time(&tmstmp,"%H:%M");
    return os;
}

