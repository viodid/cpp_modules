#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal& obj);
    virtual ~Animal();
    Animal& operator=(const Animal& obj);

    virtual void makeSound() const;
    const std::string& getType() const;

protected:
    std::string type;
};

#endif
