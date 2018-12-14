CMAKE_MINIMUM_REQUIRED(VERSION 3.7) # 3.7 is LTS as of today
SET(CMAKE_CXX_STANDARD 11) # Most syntax of the libraries require *atleast* C++11 syntax standards

SET(CMAKE_CXX_FLAGS "-g -O0 -Wall ${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# These definitions make sure UNIX OSes don't throw errors on build
if (UNIX)
  ADD_DEFINITIONS(-Wno-sign-compare -Wno-enum-compare)
endif (UNIX)

PROJECT(TestsForYungCPP)

# Preset OpenSSL directories
IF (NOT OPENSSL_ROOT_DIR)
  MESSAGE("-- Setting default OpenSSL Root Directory")
  SET(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
ENDIF (NOT OPENSSL_ROOT_DIR)

IF (NOT OPENSSL_LIBRARIES)
  MESSAGE("-- Setting default OpenSSL Library Directory")
  SET(OPENSSL_LIBRARIES "/usr/local/opt/openssl/lib")
ENDIF (NOT OPENSSL_LIBRARIES)

# Required for tests
FIND_PACKAGE(Boost COMPONENTS unit_test_framework)

# Required for YungC++ to compile
FIND_PACKAGE(Boost COMPONENTS program_options thread chrono system REQUIRED)
FIND_PACKAGE(cpprestsdk REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

MESSAGE("-- BOOST PATH \t\t" ${Boost_INCLUDE_DIR})

SET(
  REQUIRED_LIBRARIES
  cpprestsdk::cpprest
  Boost::unit_test_framework
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
  ${Boost_THREAD_LIBRARY}
  ${Boost_CHRONO_LIBRARY}
)

ENABLE_TESTING() # Enable CTest

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../src)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../src)

ADD_EXECUTABLE(
    ConfigTest
    Config.test.cpp
)

TARGET_LINK_LIBRARIES(ConfigTest ${REQUIRED_LIBRARIES})
TARGET_COMPILE_DEFINITIONS(ConfigTest PRIVATE BOOST_TEST_DYN_LINK)

ADD_EXECUTABLE(
    ServerDataTest
    ServerData.test.cpp
)

TARGET_LINK_LIBRARIES(ServerDataTest ${REQUIRED_LIBRARIES})
TARGET_COMPILE_DEFINITIONS(ServerDataTest PRIVATE BOOST_TEST_DYN_LINK)

ADD_EXECUTABLE(
    MongoShellTest
    Mongo.shell.test.cpp
)

TARGET_LINK_LIBRARIES(MongoShellTest ${REQUIRED_LIBRARIES})
TARGET_COMPILE_DEFINITIONS(MongoShellTest PRIVATE BOOST_TEST_DYN_LINK)

ADD_TEST(
    TestConfig
    ConfigTest
)

ADD_TEST(
    TestServerData
    ServerDataTest
)

ADD_TEST(
    TestMongoShell
    MongoShellTest
)
