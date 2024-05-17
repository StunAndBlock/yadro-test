#ifndef EVENT_H
#define EVENT_H


#include "TmExtension.hpp"
#include "UsefullIncludes.hpp"

namespace event{
    class Input{
        public:
        Input(TimeEx, std::string);
        Input();
        virtual ~Input();
        uint32_t id();
        protected:
        TimeEx timestamp_;
        uint32_t id_;
        std::string name_;
    };

    class ClientArrived : public Input{
        public:
        ClientArrived(TimeEx, std::string);
    
    };

    class ClientTookTable : public Input{
        public:
        ClientTookTable(TimeEx, std::string, uint32_t);
        private:
        uint32_t tableId_;
    };

    class ClientWaiting: public Input{
        public:
        ClientWaiting(TimeEx, std::string);
    };

    class ClientLeft: public Input{
        public:
        ClientLeft(TimeEx, std::string);
    };

    class Unknown: public Input{
        public:
        Unknown();
    };

}
























#endif /* !EVENT_H */