#include "../Shared.hpp"
#include "../odbc/Mongo.hpp"

#ifndef _MONGOSAMPLE_H
#define _MONGOSAMPLE_H 1

namespace yungservice {
    web::json::value mongoInsert(web::json::value result) {
        web::json::value sampleData;
        sampleData["hello"] = web::json::value::string("world");

        auto task = yungmongo::insertOne("test", sampleData);
        bool success = task.get();

        result["insertedData"] = sampleData;
        result["success"] = web::json::value(success);

        return result;
    }
}

#endif
