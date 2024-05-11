#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>


class Parser {
    public:
    Parser();
    virtual ~Parser();
    void openFile(const std::string&);
    virtual void read() = 0;

    protected:
    std::ifstream* file_;
    
    private:
    
};

class CustomTxtParser: public Parser{
    public:
    void read() override;

    private:
};





#endif /* !PARSER_HPP */