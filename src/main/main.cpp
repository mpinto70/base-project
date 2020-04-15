#include <dir/file.h>

#include <iostream>

class Implementation : dir::Interface {
public:
    Implementation() = default;
    ~Implementation() override = default;
    std::string function(int x) const override {
        return std::to_string(x);
    }
};

int main() {
    const Implementation impl;

    std::cout << dir::square(12) << std::endl;
    std::cout << impl.function(12) << std::endl;
}
