#include <string>
#include <boost/test/unit_test.hpp>
#include "Config.hpp"

#define BOOST_TEST_MODULE ConfigTest

BOOST_AUTO_TEST_SUITE(Config)

BOOST_AUTO_TEST_CASE(ConfigVariables) {

    BOOST_CHECK_EQUAL(yungconfig::host, "http://0.0.0.0");
    BOOST_CHECK_EQUAL(yungconfig::port, "3000");
    BOOST_CHECK_EQUAL(yungconfig::cors, "*");

}

BOOST_AUTO_TEST_SUITE_END()
