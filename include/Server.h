#ifndef SERVER_H
#define SERVER_H

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web; 
using namespace web::http; 
using namespace web::http::experimental::listener;

class  
{
public:
    void handlePost(http_request request);
    void handleGet(http_request request);
    http_listener listener;
private:
    Server(const std::string& address);
    void start();
};

#endif
