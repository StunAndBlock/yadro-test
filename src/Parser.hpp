#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <sstream>
#include "CoreData.hpp"
class Parser {
    public:
    enum class Status : uint8_t {BadOpen, SuccessOpen, SuccessParsed, BadParsed, BadAlloc, Initialized};
    Parser();
    virtual ~Parser();
    void openFile(const std::string&);
    virtual void parseFile() = 0;
    Status status();
    protected:
    std::ifstream* file_;
    
    private:
    Status status_;
};

class TxtParser: public Parser{
    public:
    void parseFile() override;

    private:
};

/*
class JsonParser: public Parser{

}; 
*/

/*
class XmlParser: public Parser {

};
*/



#endif /* !PARSER_HPP */