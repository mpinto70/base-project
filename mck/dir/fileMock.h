#pragma once

#include "dir/file.h"

#include <gmock/gmock.h>

namespace dir {
namespace mck {

class InterfaceMock : public Interface {
public:
    InterfaceMock();
    ~InterfaceMock() override;

    MOCK_CONST_METHOD1(function, std::string(int x));
};
}
}
