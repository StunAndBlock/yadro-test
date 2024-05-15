#ifndef CLUBCOLLECTOR_HPP
#define CLUBCOLLECTOR_HPP

#include "Parser.hpp"
#include "Core.hpp"
#include "ErrorHandler.hpp"

class ClubCollector {
    public:
    enum class Status : uint8_t {Initialized, Failed, BadCall, Success };
    ClubCollector(int, char**);
    ~ClubCollector();
    Status status();
    void exec();
    private:
    TxtParser parser_;
    Core core_;
    Status status_;
};








#endif /* !CLUBCOLLECTOR_HPP */