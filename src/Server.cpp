#include "Shared.hpp"
#include "Config.hpp"
#include "Router.hpp"

int main(int argc, char** argv) {
    namespace yungopt = boost::program_options;
    yungopt::options_description yungdescription("Yung C++ | A framework for modern web services");

    yungdescription
    .add_options()
    ("help", "print help message")
    ("host,h", yungopt::value<std::string>(&yungconfig::host), "specify host to listen on (default is http://0.0.0.0)")
    ("port,p", yungopt::value<std::string>(&yungconfig::port), "specify port to listen on (default is 3000)")
    ("cors,c", yungopt::value<std::string>(&yungconfig::cors), "specify CORS (default is * which is sometimes unsafe)")
    ("mongo", yungopt::value<std::string>(&yungconfig::mongo), "MongoDB url (default is mongodb://localhost:27017)")
    ("mongodb", yungopt::value<std::string>(&yungconfig::mongodb), "MongoDB DB name (default is yungcpp)")
    ("mysql", yungopt::value<std::string>(&yungconfig::mysql), "MySQL url (default is mysqlx://root@127.0.0.1)")
    ("mysqldb", yungopt::value<std::string>(&yungconfig::mysqldb), "MySQL DB name (default is yungcpp)")
    ("redis", yungopt::value<std::string>(&yungconfig::redis), "Redis url (default is redis://localhost:6379)");

    yungopt::variables_map vm;

    try {
        yungopt::store(yungopt::parse_command_line(argc, argv, yungdescription), vm);

        if (vm.count("help")) {
            std::cout << yungdescription << std::endl;
            return 0;
        }

        if (vm.count("host")) yungconfig::host = vm["host"].as<std::string>();
        if (vm.count("port")) yungconfig::port = vm["port"].as<std::string>();
        if (vm.count("cors")) yungconfig::cors = vm["cors"].as<std::string>();
        if (vm.count("mongo")) yungconfig::mongo = vm["mongo"].as<std::string>();
        if (vm.count("mongodb")) yungconfig::mongo = vm["mongodb"].as<std::string>();
        if (vm.count("mysql")) yungconfig::mysql = vm["mysql"].as<std::string>();
        if (vm.count("mysqldb")) yungconfig::mysqldb = vm["mysqldb"].as<std::string>();
        if (vm.count("redis")) yungconfig::redis = vm["redis"].as<std::string>();

        std::string host = yungconfig::host + ":" + yungconfig::port;
        web::http::experimental::listener::http_listener listener(host);

        listener.support(web::http::methods::GET, yungrouter::handler);
        listener.support(web::http::methods::POST, yungrouter::handler);
        listener.support(web::http::methods::PUT, yungrouter::handler);
        listener.support(web::http::methods::DEL, yungrouter::handler);
        listener.support(web::http::methods::OPTIONS, yungrouter::handler);

        try {
            std::cout << "Server starting on host: " << host << std::endl;

            if (MONGOCXX) {
                std::cout << "MongoDB Enabled on URI " << yungconfig::mongo << std::endl;
                std::cout << "MongoDB is using Database " << yungconfig::mongodb << std::endl;
            }

            listener.open().wait();
            while (true);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

    } catch (yungopt::error& e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }

   return 0;
}
