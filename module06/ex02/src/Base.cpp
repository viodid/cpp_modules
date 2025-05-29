#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

Base* generate(void)
{
    Base* out;
    std::srand(std::time(0));
    int r = std::rand();
    if (r % 3 == 0)
        out = new A();
    else if (r % 3 == 1)
        out = new B();
    else if (r % 3 == 2)
        out = new C();
    return out;
}
