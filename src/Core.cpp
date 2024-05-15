#include "Core.hpp"

Core::Core(){
    tepm_.tablesCount = 0;
    status_ = Status::Initialized;
}

Core::~Core(){

}

Core::Status Core::status(){
    return status_;
}