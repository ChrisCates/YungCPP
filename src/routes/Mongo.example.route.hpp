#include "../Shared.hpp"
#include "../services/Server.service.hpp"
#include "../services/Mongo.example.service.hpp"

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

    std::pair<web::http::status_code, std::string> mongoInsertMany() {
        web::json::value info;
        unsigned short status = 200;

        info = yungservice::metadata(info);
        info = yungservice::mongoInsertMany(info);

        std::string payload = info.serialize().c_str();
        return make_pair(status, payload);
    }

    std::pair<web::http::status_code, std::string> mongoUpdate() {
        web::json::value info;
        unsigned short status = 200;

        info = yungservice::metadata(info);
        info = yungservice::mongoUpdate(info);

        std::string payload = info.serialize().c_str();
        return make_pair(status, payload);
    }

    std::pair<web::http::status_code, std::string> mongoUpdateMany() {
        web::json::value info;
        unsigned short status = 200;

        info = yungservice::metadata(info);
        info = yungservice::mongoUpdateMany(info);

        std::string payload = info.serialize().c_str();
        return make_pair(status, payload);
    }

    std::pair<web::http::status_code, std::string> mongoFindOne() {
        web::json::value info;
        unsigned short status = 200;

        info = yungservice::metadata(info);
        info = yungservice::mongoFindOne(info);

        std::string payload = info.serialize().c_str();
        return make_pair(status, payload);
    }

    std::pair<web::http::status_code, std::string> mongoFindAll() {
        web::json::value info;
        unsigned short status = 200;

        info = yungservice::metadata(info);
        info = yungservice::mongoFindAll(info);

        std::string payload = info.serialize().c_str();
        return make_pair(status, payload);
    }
}

#endif
