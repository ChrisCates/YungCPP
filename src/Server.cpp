#include "./Shared.hpp"
#include "./Router.hpp"

int main(int argc, char** argv) {
    std::string host = "http://0.0.0.0:3000";
    web::http::experimental::listener::http_listener listener(host);

    listener.support(web::http::methods::GET, Router);
    listener.support(web::http::methods::POST, Router);
    listener.support(web::http::methods::PUT, Router);
    listener.support(web::http::methods::DEL, Router);
    listener.support(web::http::methods::OPTIONS, Router);

    try {
        std::cout << "Server starting on host: " << host << std::endl;

        listener
            .open()
            .then([&listener]() {
                std::cout << "Server started..." << std::endl;
            })
            .wait();
        while (true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

   return 0;
}
