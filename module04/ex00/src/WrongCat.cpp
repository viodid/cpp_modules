#include "../include/WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called." << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
    : WrongAnimal(obj)
{
    std::cout << "WrongCat copy constructor called." << std::endl;
    type = obj.type;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    std::cout << "WrongCat copy assignment operator called." << std::endl;
    type = obj.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong Meowww, prrrrrr..." << std::endl;
}
