#include "../Shared.hpp"
#include "../services/MongoSample.hpp"

#ifndef _EXAMPLES_H
#define _EXAMPLES_H 1

namespace yungroute {
    std::pair<web::http::status_code, std::string> mongoInsert() {
        web::json::value info;
        unsigned short status = 200;

        info = yungservice::metadata(info);
        info = yungservice::mongoInsert(info);

        std::string payload = info.serialize().c_str();
        return make_pair(status, payload);
    }
}

#endif
