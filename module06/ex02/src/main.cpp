#include "../include/Base.hpp"

int main(void)
{
    Base* base = generate();
    std::cout << base << std::endl;
    identify(base);
    return 0;
}
