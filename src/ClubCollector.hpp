#ifndef CLUBCOLLECTOR_HPP
#define CLUBCOLLECTOR_HPP

#include "Parser.hpp"
#include "Core.hpp"

class ClubCollector {
    public:
    ClubCollector(int, char**);
    ~ClubCollector();
    uint8_t status();
    private:
    CustomTxtParser pars_;
    Core main_;
    uint8_t status_;
};








#endif /* !CLUBCOLLECTOR_HPP */