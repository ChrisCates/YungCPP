CMAKE_MINIMUM_REQUIRED(VERSION 3.7) # 3.7 is LTS as of today
SET(CMAKE_CXX_STANDARD 11) # Most syntax of the libraries require *atleast* C++11 syntax standards

# These definitions make sure UNIX OSes don't throw errors on build
if (UNIX)
  ADD_DEFINITIONS(-Wno-sign-compare -Wno-enum-compare)
endif (UNIX)

PROJECT(YungCPP)

# Preset OpenSSL directories
IF (NOT OPENSSL_ROOT_DIR)
  MESSAGE("-- Setting default OpenSSL Root Directory")
  SET(OPENSSL_ROOT_DIR "/usr/local/opt/openssl")
ENDIF (NOT OPENSSL_ROOT_DIR)

IF (NOT OPENSSL_LIBRARIES)
  MESSAGE("-- Setting default OpenSSL Library Directory")
  SET(OPENSSL_LIBRARIES "/usr/local/opt/openssl/lib")
ENDIF (NOT OPENSSL_LIBRARIES)



MESSAGE("-- OPENSSL ROOT PATH \t" ${OPENSSL_ROOT_DIR})
MESSAGE("-- OPENSSL LIBRARIES \t" ${OPENSSL_LIBRARIES})

# Required for YungC++ to compile
FIND_PACKAGE(OPENSSL REQUIRED)
FIND_PACKAGE(Boost COMPONENTS program_options thread chrono system REQUIRED)
FIND_PACKAGE(cpprestsdk REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

MESSAGE("-- BOOST PATH \t\t" ${Boost_INCLUDE_DIR})

SET(
  REQUIRED_LIBRARIES
  cpprestsdk::cpprest
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
  ${Boost_THREAD_LIBRARY}
  ${Boost_CHRONO_LIBRARY}
)

# Options for drivers are default set to off
OPTION(MONGOCXX "Enable Mongo C++ Drivers" OFF)
OPTION(REDISCXX "Enable Redis C++ Drivers" OFF)
OPTION(MYSQLCXX "Enable Mongo C++ Drivers" OFF)

# Optional MongoCXX build files
IF (MONGOCXX)
  INCLUDE("${CMAKE_CURRENT_LIST_DIR}/cmake/Mongo.cmake")
  MESSAGE("-- MongoDB now enabled, MONGOCXX definition added")
  SET(
    REQUIRED_DEFINITIONS
    ${REQUIRED_DEFINITONS}
    MONGOCXX
  )
ENDIF (MONGOCXX)

# Optional RedisCXX build files
IF (REDISCXX)
INCLUDE("${CMAKE_CURRENT_LIST_DIR}/cmake/Redis.cmake")
  MESSAGE("-- Redis now enabled, REDISCXX definition added")
  SET(
    REQUIRED_DEFINITIONS
    ${REQUIRED_DEFINITONS}
    REDISCXX
  )
ENDIF (REDISCXX)

# Optional MySQLCXX build files
IF (MYSQLCXX)
  INCLUDE("${CMAKE_CURRENT_LIST_DIR}/cmake/Mysql.cmake")
  MESSAGE("-- MySQL now enabled, MYSQLCXX definition added")
  SET(
    REQUIRED_DEFINITIONS
    ${REQUIRED_DEFINITONS}
    MYSQLCXX
  )
ENDIF (MYSQLCXX)

# Create executable
ADD_EXECUTABLE(server src/Server.cpp)

# Link libraries
TARGET_LINK_LIBRARIES(
    server
    PRIVATE
    ${REQUIRED_LIBRARIES}
)

# Link definitions
TARGET_COMPILE_DEFINITIONS(
  server
  PRIVATE
  ${REQUIRED_DEFINITIONS}
)
