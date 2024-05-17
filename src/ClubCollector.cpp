#include "ClubCollector.hpp"

ClubCollector::ClubCollector(int argc, char** argv){
    if(parser_.status() == Parser::Status::Initialized &&
       core_.status() == Core::Status::Initialized){
        status_ = Status::Initialized;
        if (argc==2){
            parser_.openFile(argv[1]);
            switch (parser_.status())
            {
            case Parser::Status::BadOpen:
                status_ = Status::Failed;
                error::raise(error::Level::Fatal, 
                "input file", " `",argv[1],"` ","is missing or unable to read\n");
                break;
            default:
                status_ = Status::Success;
                break;
            }
        
        } else {
            status_ = Status::BadCall;
            error::raise(error::Level::Fatal, "missing argument\n", 
            "Exmaple usage: ", argv[0], " test_file.txt");
        }
    }
}

ClubCollector::~ClubCollector(){

}

ClubCollector::Status ClubCollector::status(){
    return status_;
}

void ClubCollector::exec(){
    try {
        parser_.parseCoreData(core_.data());
        while(parser_.parseEvent(core_.event())){
            core_.processEvent();
            
        }
    
    } catch (const std::exception& ex){
        error::raise(error::Level::Fatal, ex.what());
    }
    return;
}