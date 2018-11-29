# Yung C++ CLI Tool

**Please note that the CLI tool has not been published yet. But will be accessible via npmjs or yarn.**

## Creating a new project

**Generate a new YungC++ project in a new folder called `/Hello`**:

```bash
yungcpp new project Hello
```

## Generate a new route

**Run the command**:

```bash
yungcpp new route Hello
```

**This will create**:

```c++
#include "../Shared.hpp"

#ifndef _HELLOROUTE_H
#define _HELLOROUTE_H 1

namespace yungroute {
    std::pair<web::http::status_code, std::string> hello() {
        web::json::value info;
        unsigned short status = 200;

        info = yungservice::metadata(info);

        std::string payload = info.serialize().c_str();
        return make_pair(status, payload);
    }
}

#endif
```

## Generate a new service

**Run the command**:

```bash
yungcpp new service Hello
```

**This will create**:

```c++
#include "../Shared.hpp"

#ifndef _HELLOSERVICE_H
#define _HELLOSERVICE_H 1

namespace yungservice {
    web::json::value hello(web::json::value info) {
        return info;
    }
}

#endif
```
