#include "../include/Array.hpp"
#include <iostream>
#include <ostream>

int main(void)
{
    Array<float> a(3);
    Array<float> b(a);
    try {
        std::cout << b[3] << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    a.getArr();
    return 0;
}
