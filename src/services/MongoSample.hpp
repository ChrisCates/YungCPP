#include "../Shared.hpp"

#ifndef _MONGOSAMPLE_H
#define _MONGOSAMPLE_H 1

namespace yungservice {
    web::json::value mongoInsert(web::json::value result) {
        web::json::value sampleData;
        sampleData["hello"] = web::json::value::string("world");

        bool success = false;

        if (MONGOCXX) {
            auto task = yungmongo::insertOne("test", sampleData);
            success = task.get();
        } else {
            result["message"] = web::json::value::string("MongoDB Drivers are not enabled");
        }


        result["insertedData"] = sampleData;
        result["success"] = web::json::value(success);

        return result;
    }

    web::json::value mongoInsertMany(web::json::value result) {
        web::json::value sampleData;
        sampleData[0]["hello"] = web::json::value::string("world 1");
        sampleData[1]["hello"] = web::json::value::string("world 2");
        sampleData[2]["hello"] = web::json::value::string("world 3");

        bool success = false;

        if (MONGOCXX) {
            auto task = yungmongo::insertMany("test", sampleData);
            success = task.get();
        } else {
            result["message"] = web::json::value::string("MongoDB Drivers are not enabled");
        }


        result["insertedData"] = sampleData;
        result["success"] = web::json::value(success);

        return result;
    }

    web::json::value mongoUpdate(web::json::value result) {
        web::json::value filterData;
        filterData["hello"] = web::json::value::string("world");

        web::json::value newData;
        newData["updated"] = true;

        web::json::value options;
        options["upsert"] = true;

        bool success = false;

        if (MONGOCXX) {
            auto task = yungmongo::updateOne("test", filterData, newData, options);
            success = task.get();
        } else {
            result["message"] = web::json::value::string("MongoDB Drivers are not enabled");
        }

        result["success"] = web::json::value(success);

        return result;
    }

    web::json::value mongoUpdateMany(web::json::value result) {
        web::json::value filterData;
        filterData["hello"] = web::json::value::string("world");

        web::json::value newData;
        newData["updated_all"] = true;

        web::json::value options;
        options["upsert"] = true;

        bool success = false;

        if (MONGOCXX) {
            auto task = yungmongo::updateMany("test", filterData, newData, options);
            success = task.get();
        } else {
            result["message"] = web::json::value::string("MongoDB Drivers are not enabled");
        }

        result["success"] = web::json::value(success);

        return result;
    }

    web::json::value mongoFindOne(web::json::value result) {
        web::json::value placeholder = web::json::value::parse("{}");

        if (MONGOCXX) {
            auto task = yungmongo::findOne("test", placeholder, placeholder);
            std::string data = task.get();
            result["data"] = web::json::value::parse(data);
        } else {
            result["message"] = web::json::value::string("MongoDB Drivers are not enabled");
        }

        return result;
    }

    web::json::value mongoFindAll(web::json::value result) {
        web::json::value placeholder = web::json::value::parse("{}");

        if (MONGOCXX) {
            auto task = yungmongo::findAll("test", placeholder, placeholder);
            result["data"] = task.get();
        } else {
            result["message"] = web::json::value::string("MongoDB Drivers are not enabled");
        }

        return result;
    }
}

#endif
