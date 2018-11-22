CMAKE_MINIMUM_REQUIRED(VERSION 3.7) # 3.7 is LTS as of today
SET(CMAKE_CXX_STANDARD 11) # Most syntax of the libraries require *atleast* C++11 syntax standards

if (UNIX)
  ADD_DEFINITIONS(-Wno-sign-compare -Wno-enum-compare)
endif(UNIX)

PROJECT(YungCPP)

# Required for CPP REST SDK
FIND_PACKAGE(Boost COMPONENTS thread chrono system REQUIRED)
FIND_PACKAGE(cpprestsdk REQUIRED)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# Create executable
ADD_EXECUTABLE(server src/Server.cpp)

# Link libraries
TARGET_LINK_LIBRARIES(
    server
    PRIVATE
    cpprestsdk::cpprest
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_CHRONO_LIBRARY}
)
