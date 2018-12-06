#include "../Shared.hpp"
#include "../Config.hpp"

#ifndef _MONGO_H
#define _MONGO_H 1

#ifdef MONGOCXX
    namespace yungmongo {
        mongocxx::instance MongoInstance{};
        mongocxx::uri uri(yungconfig::mongo);
        mongocxx::pool pool{uri};

        std::string db = yungconfig::mongodb;

        pplx::task<bool> insertOne(std::string collection, web::json::value data) {
            return pplx::task<bool>([=] {
                try {
                    auto poolInstance = pool.acquire();
                    auto client = (*poolInstance)[db][collection];

                    auto dataString = data.serialize().c_str();
                    auto document = bsoncxx::from_json(dataString);

                    client.insert_one(document.view());

                    return true;
                } catch (std::exception &e) {
                    std::cout << e.what() << std::endl;
                    return false;
                }
            });
        }
    }
#else
    namespace yungmongo {
        pplx::task<bool> insertOne(std::string collection, web::json::value data) {
            return pplx::task<bool>([=] {
                return false;
            });
        }
    }
#endif

#endif
