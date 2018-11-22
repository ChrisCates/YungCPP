#include "../Shared.hpp"

#ifndef _SERVERINFO_H
#define _SERVERINFO_H 1

std::pair<web::http::status_code, std::string> ServerInfo() {
    web::json::value info;

    info = AppendServerData(info);

    std::string payload = info.serialize().c_str();
    return make_pair(web::http::status_codes::OK, payload);
}

#endif
