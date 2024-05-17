#include "Parser.hpp"
#include <regex>
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
    uint32_t v;
    try {
    long long value = std::stoll(strRepr);
    if (value <= 0){
        throw(std::runtime_error(info));
    }
    v = std::stoul(strRepr);
    } catch (std::exception&){
        throw(std::runtime_error(info));
    }
    return v;
    
};

TimeEx timeTypeCheck(const std::string& strRepr,
                            const std::string& info= std::string()){
    std::istringstream ss;
    ss.str(strRepr);
    struct std::tm value;
    if(!(ss>>std::get_time(&value, "%H:%M"))){
        throw(std::runtime_error(info));
    }
    return TimeEx(value);
}

std::string nameCheck(const std::string& name,
                            const std::string& info= std::string()){
    std::regex pattern("^([a-z]|[0-9]|_|-)+$");
    if(!std::regex_match(name, pattern)){
        throw(std::runtime_error(info));
    }
    return name;
}

void TxtParser::parseCoreData(CoreData* data){
    
    std::string strTablesCount;
    std::string strStartEndTime;
    std::string strCostPerHour;

    std::getline(*file_,strTablesCount);
    if(file_->fail()){
        throw(std::runtime_error("\n\t<- Expected: tables [1-N]\n" ));
    }
    data->tablesCount = unsignedTypeCheck(strTablesCount,"\n" + strTablesCount + "\t<- Expected: tables [1-N]\n");
    if(file_->eof()){
        throw(std::runtime_error("\n" + strTablesCount + "\n\t<- Expected: HH:MM HH:MM Got: EOF\n" ));
    }

    std::getline(*file_,strStartEndTime);
    if(file_->fail()){
        throw(std::runtime_error("\n" + strTablesCount + "\n\t<- Expected: HH:MM HH:MM\n" ));
    }
    size_t pos = 0;
    if (( pos = strStartEndTime.find(' ')) != std::string::npos){
        data->startTime = timeTypeCheck(strStartEndTime.substr(0, pos), "\n" + strStartEndTime + "\t<- Expected: HH:MM HH:MM\n");
        data->endTime = timeTypeCheck(strStartEndTime.substr(pos+1, strStartEndTime.length()), "\n" + strStartEndTime + "\t<- Expected: HH:MM HH:MM\n");
    } else {
        throw(std::runtime_error("\n" + strStartEndTime + "\t<- Expected: HH:MM HH:MM\n"));
    }   
    if(file_->eof()){
        throw(std::runtime_error("\n" + strStartEndTime  + "\n\t<- Expected: cost per hour [1-N] Got: EOF \n" ));
    }

    std::getline(*file_,strCostPerHour);
    if(file_->fail()){
        throw(std::runtime_error("\n" + strStartEndTime + "\n\t<- Expected: cost per hour [1-N]\n" ));
    }
    data->costPerHour = unsignedTypeCheck(strCostPerHour,"\n" + strCostPerHour + "\t<- Expected: cost per hour [1-N]\n");
    if(file_->eof()){
        throw(std::runtime_error("\n" + strStartEndTime + "\n\t<- Expected: events Got: EOF \n"));
    }
    //std::cout<<data->tablesCount<< data->endTime << data->startTime << data->costPerHour;
    return ;
}

bool TxtParser::parseEvent(std::shared_ptr<event::Input>& event){


    std::string strEvent;
    std::getline(*file_,strEvent);
    if(file_->fail()){
        throw(std::runtime_error(strEvent ));
    }
    std::string errorHere = strEvent;
    size_t pos = 0;
    if (( pos = strEvent.find(' ')) == std::string::npos){
        throw std::runtime_error(errorHere);
    }
    TimeEx timeStamp = timeTypeCheck(strEvent.substr(0, pos), errorHere);
    strEvent.erase(0, pos + 1);
    if (( pos = strEvent.find(' ')) == std::string::npos){
        throw std::runtime_error(errorHere);
    }
   
    uint32_t id = unsignedTypeCheck(strEvent.substr(0, pos), errorHere);
    strEvent.erase(0, pos + 1);

    std::string clientName ;
    if (( pos = strEvent.find(' ')) != std::string::npos && id == 2){
        clientName = nameCheck(strEvent.substr(0, pos), errorHere);
        strEvent.erase(0, pos + 1);
    } else {
        clientName = nameCheck(strEvent.substr(0,strEvent.length()), errorHere);
    }
    

    switch (id)
    {
    case 1:
        break;
    case 2:

        break;
    case 3:
    case 4:
    default:
        break;
    }

    std::cout<<timeStamp<< id << clientName;
    // if(((*file_) >> timeStamp >> id >> clientName)){
    //     TimeEx ts_t = timeTypeCheck(timeStamp, "event time stamp");
    //     uint32_t id_t = unsignedTypeCheck(id, "id");
    //     switch (id_t)
    //     {
    //     case 1:
    //         event = std::make_shared<event::ClientArrived>(ts_t, clientName);
    //         break;
    //     case 2:
    //         if(((*file_) >> tableId)){
    //             uint32_t tid_t = unsignedTypeCheck(tableId, "table number");
    //             event = std::make_shared<event::ClientTookTable>(ts_t, clientName, tid_t);
    //         } else {
    //             throw(std::runtime_error("type 2 event expects table id"));
    //         }
    //         break;
    //     case 3:
    //         event = std::make_shared<event::ClientWaiting>(ts_t, clientName);
    //         break;
    //     case 4:
    //         event = std::make_shared<event::ClientLeft>(ts_t, clientName);
    //         break;        
    //     default:
    //         event = std::make_shared<event::Unknown>();
    //         break;
    //     }
    // } else {
    //     return false;
    // }
    return !file_->eof();
}
//get_time(&data.endTime, "%H:%M")