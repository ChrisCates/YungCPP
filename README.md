# Yung C++

![License](https://img.shields.io/badge/license-MIT-blue.svg)
[![Build Status](https://travis-ci.org/ChrisCates/YungCPP.svg?branch=master)](https://travis-ci.org/ChrisCates/YungCPP)
[![codecov](https://codecov.io/gh/ChrisCates/YungCPP/branch/master/graph/badge.svg)](https://codecov.io/gh/ChrisCates/YungCPP)
![C++ Standard](https://img.shields.io/badge/cmake%20standard-C++%2011-brightgreen.svg)
![CMake](https://img.shields.io/badge/cmake%20version-3.7-green.svg)


A framework for structuring Web Services in C++. Designed to work with the MySQL, Mongo and Redis C++ drivers. The intention is to build a scalable, easy to use HTTP(S) Web Server and Client for REST APIs and Websockets. The focus will be primarily to support UNIX OSes.

## Command Line Interface

A command line interface to bootstrap projects and generate routes and services is available via npmjs and yarn. You can learn about the command line tool [here](https://github.com/ChrisCates/YungCLI).

## Requirements

### Required for build

1. [C++ REST SDK](https://github.com/Microsoft/cpprestsdk).

2. [Boost Core](https://github.com/boostorg/boost/wiki/Getting-Started).

3. [OpenSSL](https://github.com/openssl/openssl).

4. CMake LTS, Make LTS

### Optional requirements

5. [MongoDB](https://github.com/mongodb/mongo)
	- Before install C++ drivers, you need to install [the C drivers first](https://github.com/mongodb/mongo-c-driver/releases).
  - Once C drivers installed you can install [the C++ drivers](http://mongocxx.org/mongocxx-v3/installation/).

6. [Redis](https://github.com/antirez/redis/)
  - The C drivers are interacted with directly without C++ using [hiredis](https://github.com/redis/hiredis).

7. [MySQL](https://github.com/mysql/mysql-server)
  - The [mysql-connect-cpp drivers](https://github.com/mysql/mysql-connector-cpp) are used to interact with MySQL.

## Building with CMake

CMake will always be the best way to interface with the YungCPP framework. Support will always be up to date for Mac OS and Debian systems. I am open to contributions to support Windows.

### Standard Build

**1. Make the build directory**

```bash
mkdir build
cd build
```

**2. Make the cmake file with CMakeLists.txt. Please note that you will need to verbosely specify the directories for your OpenSSL libraries, as sometimes they are inconsistent on various OSes.**

```bash
cmake -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib ..
make
```

**3. Run the server binary**

```bash
./server
```

**4. (Optional) Add flags for drivers**

Run CMake with the following optional flags:

```bash
cmake -DMONGOCXX=ON # To enable MongoDB
cmake -DREDISCXX=ON # To enable Hiredis
cmake -DMYSQLCXX=ON # To enable MySQL
```

### Custom flags

The binary also comes with custom command line options:

```bash
$ server --help
Yung C++ | A framework for modern web services:
  --help                print help message
  -h [ --host ] arg     specify host to listen on (default is http://0.0.0.0)
  -p [ --port ] arg     specify port to listen on (default is 3000)
  -c [ --cors ] arg     specify CORS (default is * which is sometimes unsafe)
  --mongo arg           MongoDB url (default is mongodb://localhost:27017)
  --mongodb arg         MongoDB DB name (default is yungcpp)
```

This way you can change the default host and port if necessary.

## Additional Resources

- I will be publishing full documentation on https://yungcpp.chriscates.ca upon V1 initial release.

- There will also be a tutorial on usage on webpage https://chriscates.ca/a/yungcpp.

- If you are interested in contributing or want to get in contact. Email me at :mailbox: hello@chriscates.ca
