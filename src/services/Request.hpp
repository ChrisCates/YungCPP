#include "../Shared.hpp"

#ifndef _REQUEST_H
#define _REQUEST_H 1

namespace yunghttp {

    web::http::client::http_client_config requestConfig(web::json::value configParams) {
        web::http::client::http_client_config config;

        if (configParams["credentials"].is_object()) {
            http::client::credentials credentials;
            std::string username = configParams["credentials"]["username"].as_string();
            std::string password = configParams["credentials"]["password"].as_string();

            credentials = http::client::credentials(username, password);
            config.set_credentials(credentials);
        }

        if (configParams["timeout"].is_integer()) {
            config.set_timeout(configParams["timeout"].as_integer());
        }

        return config;
    }

    pplx::task<web::http::http_response> request(web::http::methods method, std::string url, web::json::value body, web::json::value configParams) {
        return pplx::task<web::http::http_response>([=] {
            try {
                web::http::client::http_client_config config = requestConfig(configParams);
                web::http::client::http_client client(url, config);

                web::http::http_response response;

                if (body.is_boolean()) {
                    response = client.request(method);
                } else {
                    response = client.request(method, "", body);
                }

                return response;
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
                web::http::http_response response;
                response.set_status_code(500);
                response.set_reason_phrase("Something went wrong creating the request");

                return response;
            }
        });

    }
}

#endif
