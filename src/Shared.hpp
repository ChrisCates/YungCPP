#ifndef _SHARED_H
#define _SHARED_H 1

// API Dependencies
#include "boost/program_options.hpp"

#include <cpprest/http_listener.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <iostream>
#include <map>
#include <set>
#include <string>

// MongoDB Drivers
#ifdef MONGOCXX
    #define USEMONGO 1
    #include <bsoncxx/builder/stream/document.hpp>
    #include <bsoncxx/builder/basic/array.hpp>
    #include <bsoncxx/builder/basic/document.hpp>
    #include <bsoncxx/builder/basic/kvp.hpp>
    #include <bsoncxx/json.hpp>

    #include <mongocxx/client.hpp>
    #include <mongocxx/pool.hpp>
    #include <mongocxx/instance.hpp>
    #include <mongocxx/options/find.hpp>
    #include <mongocxx/uri.hpp>

    #include "odbc/Mongo.hpp"
#else
    #define USEMONGO 0

    #include "odbc/Mongo.shell.hpp"
#endif

#endif
