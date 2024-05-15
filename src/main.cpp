#include "ClubCollector.hpp"


int main(int argc, char** argv){

    ClubCollector app(argc,argv);

    switch (app.status())
    {
    case ClubCollector::Status::Success:
        app.exec();
        break;
    
    default:
        break;
    }

    return static_cast<int>(app.status());
}