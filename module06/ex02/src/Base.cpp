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
    else {
        std::cout << "error srand" << std::endl;
        exit(EXIT_FAILURE);
    }
    return out;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Pointer doesn't correspond to any child class" << std::endl;
}
