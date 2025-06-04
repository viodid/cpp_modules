#include "../include/Array.hpp"
#include <iostream>
#include <ostream>

int main(void)
{
    Array<float> a(3);
    Array<float> b(a);
    std::cout << b.getArr() << std::endl;
    a.getArr();
    return 0;
}
