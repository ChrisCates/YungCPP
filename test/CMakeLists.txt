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
    test.cpp
    Config.test.cpp
)

TARGET_LINK_LIBRARIES(ConfigTest ${REQUIRED_LIBRARIES})
TARGET_COMPILE_DEFINITIONS(ConfigTest PRIVATE BOOST_TEST_DYN_LINK)

ADD_EXECUTABLE(
    ServerDataTest
    test.cpp
    ServerData.test.cpp
)

TARGET_LINK_LIBRARIES(ServerDataTest ${REQUIRED_LIBRARIES})
TARGET_COMPILE_DEFINITIONS(ServerDataTest PRIVATE BOOST_TEST_DYN_LINK)

ADD_TEST(
    TestConfig
    ConfigTest
)

ADD_TEST(
    TestServerData
    ServerDataTest
)