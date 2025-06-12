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
    Array<t_test> d(42);
    d[3].n = 42;
    d[3].s = "Arthur... think twice.";
    std::cout << "number: " << d[3].n << std::endl;
    std::cout << "string: " << d[3].s << std::endl;
    Array<float> e;
    try {
        std::cout << e[0] << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Uninitialized values
    // std::cout << "number: " << d[4].n << std::endl;
    // std::cout << "string: " << d[4].s << std::endl;
    return 0;
}
