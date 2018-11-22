#include "../Shared.hpp"

#ifndef _SERVERDATA_H
#define _SERVERDATA_H 1

web::json::value AppendServerData(web::json::value info) {
    info[U("version")] = web::json::value::string(U("0.0.1"));
    info[U("server")] = web::json::value::string(U("YungCPP"));

    return info;
}

#endif
