#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <iostream>
#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& obj);
    virtual ~WrongAnimal();
    WrongAnimal& operator=(const WrongAnimal& obj);
    void makeSound() const;
    const std::string& getType() const;

protected:
    std::string type;
};

#endif
