#include "Server.h"
#include "SIPMessage.h"
#include "STUN.h"

Server::Server(const std::string& address) : listener(http_listener(U(address))) {
    listener.support(methods::POST, std::bind(&Server::handlePost, this, std::placeholders::_1));
    listener.support(methods::GET, std::bind(&Server::handleGet, this, std::placeholders::_1));
}

void Server::start() {
    listener.open().wait();
}

void Server::handlePost(http_request request) {
    request.extract_json().then([=](json::value jsonObject) {
        auto type = jsonObject[U("type")].as_string();
        auto from = jsonObject[U("from")].as_string();
        auto to = jsonObject[U("to")].as_string();

        SIPMessage message(type, from, to);
        ucout << message.toString() << std::endl;

        json::value response;
        response[U("status")] = json::value::string(U("Message received"));
        request.reply(status_codes::OK, response);
    }).wait();
}

void Server::handleGet(http_request request) {
    auto query = uri::split_query(request.request_uri().query());

    if (query.find(U("address")) != query.end()) {
        auto address = query[U("address")];

        json::value response;
        response[U("publicAddress")] = json::value::string(U(STUN::getPublicAddress(address)));
        response[U("relayAddress")] = json::value::string(U(STUN::getRelayAddress(address)));

        request.reply(status_codes::OK, response);
    } else {
        request.reply(status_codes::BadRequest, U("Query parameter 'address' is missing"));
    }
}
