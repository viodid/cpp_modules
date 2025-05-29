#include "../include/Base.hpp"

class D : public Base { };

int main(void)
{
    Base* base = generate();
    identify(base);
    Base& base_ref = *base;
    identify(base_ref);
    std::cout << "=== Wrong Class ===" << std::endl;
    D wrong;
    identify(&wrong);
    Base& wrong_ref = wrong;
    identify(wrong_ref);
    delete base;
    return 0;
}
