#include <SIPMessage.h>

SIPMessage::SIPMessage(const std::string& type, const std::string& from, const std::string& to) 
    : type(type), from(from), to(to) {}

std::string SIPMessage::getType() const {
    return type;
}

std::string SIPMessage::getFrom() const {
    return from;
}

std::string SIPMessage::getTo() const {
    return to;
}

std::string SIPMessage::toString() const {
    return "Type: " + type + "\nFrom: " + from + "\nTo: " + to;
}