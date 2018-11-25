#pragma once

#include <string>

namespace dir {

int square(int x);

class Interface {
public:
    virtual ~Interface() = default;
    virtual std::string function(int x) const = 0;
};
}
