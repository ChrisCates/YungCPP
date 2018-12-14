#include "../Shared.hpp"
#include "../Config.hpp"

#ifndef _MONGO_H
#define _MONGO_H 1

namespace yungmongo {
    pplx::task<bool> insertOne(std::string collection, web::json::value data) {
        return pplx::task<bool>([=] {
            return false;
        });
    }

    pplx::task<bool> insertMany(std::string collection, web::json::value data) {
        return pplx::task<bool>([=] {
            return false;
        });
    }

    pplx::task<bool> updateOne(std::string collection, web::json::value filter, web::json::value data, web::json::value optionsParams) {
        return pplx::task<bool>([=] {
            return false;
        });
    }

    pplx::task<bool> updateMany(std::string collection, web::json::value filter, web::json::value data, web::json::value optionsParams) {
        return pplx::task<bool>([=] {
            return false;
        });
    }

    pplx::task<web::json::value> findOne(std::string collection, web::json::value filter, web::json::value optionsParams) {
        return pplx::task<web::json::value>([=] {
            return web::json::value::parse("{}");
        });
    }

    pplx::task<web::json::value> findAll(std::string collection, web::json::value filter, web::json::value optionsParams) {
        return pplx::task<web::json::value>([=] {
            return web::json::value::parse("[]");
        });
    }

    pplx::task<bool> deleteOne(std::string collection, web::json::value filter) {
        return pplx::task<bool>([=] {
            return false;
        });
    }

    pplx::task<bool> deleteMany(std::string collection, web::json::value filter) {
        return pplx::task<bool>([=] {
            return false;
        });
    }
}

#endif
