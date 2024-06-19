#include "STUN.h"

std::string STUN::getPublicAddress(const std::string& privateAddress) {
    return "publi_"+ privateAddress;
}

std::string STUN::getRelayAddress(const std::string& privateAddress) {
    return "relay_"+ privateAddress;
}

