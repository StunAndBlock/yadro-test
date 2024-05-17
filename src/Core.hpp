#ifndef CORE_HPP
#define CORE_HPP

#include "Usefullincludes.hpp"
#include "CoreData.hpp"
#include "ErrorHandler.hpp"
class Core {
public:
    Core();
    ~Core();
    enum class Status : uint8_t {BadOpen, SuccessOpen, SuccessParsed, BadParsed, BadAlloc, Initialized};
    Status status();
    struct CoreData* data();
    std::shared_ptr<event::Input>& event();
    void processEvent();
    void processEvent(event::ClientArrived);
    void processEvent(event::ClientTookTable);
    void processEvent(event::ClientWaiting);
    void processEvent(event::ClientLeft);
    void processEvent(event::Unknown);
private:
    Status status_;
    struct CoreData* data_; 
    std::shared_ptr<event::Input> event_;
};








#endif /* !CORE_HPP */