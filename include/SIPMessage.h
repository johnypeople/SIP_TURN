#ifndef SIPMESSAGE_H
#define SIPMESSAGE_H

#include <string>

class SIPMessage {
    public:
        SIPMessage(const std::string& type, const std::string& from, const std::string& to);
        std::string getType() const; 
        std::string getFrom() const; 
        std::string getTo() const;
        std::string toString() const;
        
    
    private:
        std::string type;
        std::string from;
        std::string to;
};

#endif //SIPMESSAGE_H