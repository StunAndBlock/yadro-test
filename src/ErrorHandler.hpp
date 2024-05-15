#ifndef ERROR_H
#define ERROR_H

#include <string>
#include "UsefullIncludes.hpp"



#include <iostream>
namespace error
{
    enum class Level : uint8_t {Warning, Fatal};
    template<typename T, typename... Args>
    void raise(T level, Args&&... args){
    switch (level)
    {
    case error::Level::Warning:
        std::cerr << "Warning: ";
        break;
    case error::Level::Fatal:
        std::cerr << "Fatal error: ";
        break;
    default:
        std::cerr << "Error:";
        break;
    }
    ((std::cerr << std::forward<Args>(args)), ...);
}

} // namespace 









#endif /* !ERROR_H */