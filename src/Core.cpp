#include "Core.hpp"

Core::Core(){
    try{
        data_ = new CoreData;
        status_ = Status::Initialized;
    } catch (const std::bad_alloc&) {
        status_ = Status::BadAlloc;
    }
}

Core::~Core(){

}

Core::Status Core::status(){
    return status_;
}

struct CoreData* Core::data(){
    return data_;
}

std::shared_ptr<event::Input>& Core::event(){
    return event_;
}

void Core::processEvent(){
    switch (event_->id())
    {
    case 1:
        this->processEvent(*std::dynamic_pointer_cast<event::ClientArrived>(event_));
        break;
    case 2:
        this->processEvent(*std::dynamic_pointer_cast<event::ClientTookTable>(event_));
        break;
    case 3:
        this->processEvent(*std::dynamic_pointer_cast<event::ClientWaiting>(event_));
        break;
    case 4:
        this->processEvent(*std::dynamic_pointer_cast<event::ClientLeft>(event_));
        break;    
    default:
        this->processEvent(*std::dynamic_pointer_cast<event::Unknown>(event_));
        break;
    }
}

void Core::processEvent(event::ClientArrived){
    std::cout<< event_->id();
}
void Core::processEvent(event::ClientTookTable){
    std::cout<<"aaa"<< event_->id();
}
void Core::processEvent(event::ClientWaiting){
    std::cout<< event_->id();
}
void Core::processEvent(event::ClientLeft){
    std::cout<< event_->id();
}

void Core::processEvent(event::Unknown){
    error::raise(error::Level::Warning, "Encounter: unknown event ");
}