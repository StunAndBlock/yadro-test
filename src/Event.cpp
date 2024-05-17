#include "Event.hpp"


using namespace event;
Input::~Input(){
    ;
}

Input::Input(TimeEx timeStamp, std::string name){
    timestamp_ = timeStamp;
    name_ = name;
}

Input::Input(){
    timestamp_ = TimeEx();
    name_ = std::string();
}


uint32_t Input::id(){
    return id_;
}

ClientArrived::ClientArrived(TimeEx timeStamp, 
                            std::string name) : Input(timeStamp, name){
    id_ = 1;                             
}




ClientTookTable::ClientTookTable(TimeEx timeStamp, 
                                std::string name, 
                                uint32_t tableId) : Input(timeStamp, name){
    id_ = 2;
    tableId_ = tableId;
}

ClientWaiting::ClientWaiting(TimeEx timeStamp, 
                            std::string name) : Input(timeStamp, name){
    id_ = 3;                             
}

ClientLeft::ClientLeft(TimeEx timeStamp, 
                            std::string name) : Input(timeStamp, name){
    id_ = 4;                             
}

Unknown::Unknown(){
    id_ = 5;                             
}
