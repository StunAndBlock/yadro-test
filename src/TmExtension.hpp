#ifndef TMEXTENSION_H
#define TMEXTENSION_H



#include <ctime>
#include <iostream>
#include <iomanip>

class TimeEx {
    public:
    TimeEx();
    TimeEx(int, int, int);
    TimeEx(struct std::tm);
    //TimeEx(std::string);
    //void fromString(std::string&);
    bool operator>(const TimeEx& rhs) const;
    bool operator>=(const TimeEx& rhs) const;
    bool operator<(const TimeEx& rhs) const;
    friend std::ostream& operator<<(std::ostream&, const TimeEx&);
    void makeNextDay();
    private:
    int tm_total_min_;
    int tm_hour;
    int tm_min;
    int tm_day;
    void updateTotalMin();

};











#endif /* !TMEXTENSION_H */