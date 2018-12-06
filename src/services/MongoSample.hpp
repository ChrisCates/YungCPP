#include "../Shared.hpp"

#ifndef _MONGOSAMPLE_H
#define _MONGOSAMPLE_H 1

namespace yungservice {
    web::json::value mongoInsert(web::json::value result) {
        web::json::value sampleData;
        sampleData["hello"] = web::json::value::string("world");

        bool success = false;

        if (USEMONGO) {
            auto task = yungmongo::insertOne("test", sampleData);
            success = task.get();
        } else {
            result["message"] = web::json::value::string("MongoDB Drivers are not enabled");
        }


        result["insertedData"] = sampleData;
        result["success"] = web::json::value(success);

        return result;
    }
}

#endif
