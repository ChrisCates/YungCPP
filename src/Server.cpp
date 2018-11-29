#include "./Shared.hpp"
#include "./Config.hpp"
#include "./Router.hpp"

int main(int argc, char** argv) {
    namespace yungopt = boost::program_options;
    yungopt::options_description yungdescription("Yung C++ | A framework for modern web services");

    yungdescription
    .add_options()
    ("help", "print help message")
    ("host,h", yungopt::value<std::string>(&yungconfig::host), "specify host to listen on (default is http://0.0.0.0)")
    ("port,p", yungopt::value<std::string>(&yungconfig::port), "specify port to listen on (default is 3000)")
    ("cors,c", yungopt::value<std::string>(&yungconfig::cors), "specify CORS (default is * which is sometimes unsafe)");

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

        std::string host = yungconfig::host + ":" + yungconfig::port;
        web::http::experimental::listener::http_listener listener(host);

        listener.support(web::http::methods::GET, yungrouter::handler);
        listener.support(web::http::methods::POST, yungrouter::handler);
        listener.support(web::http::methods::PUT, yungrouter::handler);
        listener.support(web::http::methods::DEL, yungrouter::handler);
        listener.support(web::http::methods::OPTIONS, yungrouter::handler);

        try {
            std::cout << "Server starting on host: " << host << std::endl;
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
