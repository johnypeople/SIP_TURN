#ifndef STUN_H
#define STUN_H

#include <string>

class STUN {
    public:
        static std::string getPublicAddress(const std::string& privateAddress);
        static std::string getRelayAddress(const std::string& privateAddress);
};

#endif // STUN_H