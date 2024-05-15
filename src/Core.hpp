#ifndef CORE_HPP
#define CORE_HPP

#include "Usefullincludes.hpp"
#include "CoreData.hpp"

class Core {
public:
    Core();
    ~Core();
    enum class Status : uint8_t {BadOpen, SuccessOpen, SuccessParsed, BadParsed, BadAlloc, Initialized};
    Status status();
private:
    Status status_;
    struct CoreData tepm_; 
};








#endif /* !CORE_HPP */