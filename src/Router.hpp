#include "./Shared.hpp"
#include "./routes/ServerInfo.hpp"

#ifndef _ROUTER_H
#define _ROUTER_H 1

void Router(web::http::http_request request) {
    web::uri requestUri = request.request_uri();

    std::cout << "[" + request.method() + "] Request to " << requestUri.path() << std::endl;

    if (requestUri.path() == "/") {
        std::pair<web::http::status_code, std::string> response = ServerInfo();
        request.reply(response.first, response.second, "application/json");
    } else {
        std::pair<web::http::status_code, std::string> response = ServerInfo();
        request.reply(response.first, response.second, "application/json");
    }
}

#endif
