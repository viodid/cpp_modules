#include "../include/Array.hpp"
#include <iostream>
#include <ostream>

int main(void)
{
    Array<float> a(3);
    Array<float> b(a);
    Array<float> c = b;
    try {
        std::cout << b[3] << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << c.size() << std::endl;
    return 0;
}
