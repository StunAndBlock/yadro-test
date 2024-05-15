#include "Parser.hpp"
Parser::Parser(){
    try {
        file_ = new std::ifstream;
        status_ = Status::Initialized;
    } catch (std::bad_alloc&){
        status_ = Status::BadAlloc;
    }
}

Parser::~Parser(){
    if (file_){
        file_->close();
        delete file_;
    }
}

void Parser::openFile(const std::string& fileName){
    file_->open(fileName);
    if (file_->is_open()){
        status_ = Status::SuccessOpen;
    } else {
        status_ = Status::BadOpen;
    }
    return ;
}

Parser::Status Parser::status(){
    return status_;
}

uint32_t unsignedTypeCheck(const std::string& strRepr, 
                            const std::string& info = std::string()){
    long long value = std::stoll(strRepr);
     if (value < 0){
            throw(std::runtime_error(std::string("bad " + info + "value ")));
    }
    return std::stoul(strRepr);
};

TimeEx timeTypeCheck(const std::string& strRepr,
                            const std::string& info= std::string()){
    std::istringstream ss;
    ss.str(strRepr);
    struct std::tm value;
    if(!(ss>>std::get_time(&value, "%H:%M"))){
        throw(std::runtime_error("bad " + info + " value"));
    }
    return TimeEx(value);
}


void TxtParser::parseFile(){
    CoreData data;
    std::string strTablesCount;
    std::string strStartTime;
    std::string strEndTime;
    std::string strCostPerHour;
    std::istringstream ss;

    if(((*file_)>>strTablesCount
    >>strStartTime
    >>strEndTime
    >>strCostPerHour)){
        data.tablesCount = unsignedTypeCheck(strTablesCount, "tables count");
        data.costPerHour =  unsignedTypeCheck(strCostPerHour, "cost per hour");
        data.startTime = timeTypeCheck(strStartTime, "start time");
        data.endTime = timeTypeCheck(strEndTime, "end time");
        if (data.startTime > data.endTime){
            throw(std::runtime_error("start time > end time"));
        }
    } else {
        throw(std::runtime_error("read failure"));
    }
    std::cout<<data.startTime;
}

//get_time(&data.endTime, "%H:%M")