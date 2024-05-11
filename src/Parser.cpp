#include "Parser.hpp"

Parser::Parser(){
    file_ = nullptr;
}

Parser::~Parser(){
    if (file_){
        file_->close();
        delete file_;
    }
}

void Parser::openFile(const std::string& fileName){
    try {
        file_->open(fileName);
        file_->exceptions(std::ios::failbit);
        //status_ = Data::Status::Occupied;
    } catch (std::ios::failure&){
        //status_ = Data::Status::BadFile;
    }
    return ;
}