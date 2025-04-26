#ifndef CAT_H
#define CAT_H
#include "../include/AAnimal.hpp"
#include "../include/Brain.hpp"

class Cat : public AAnimal {
public:
    Cat();
    Cat(const Cat& obj);
    ~Cat();
    Cat& operator=(const Cat& obj);
    void makeSound() const;
    Brain* getBrain() const;
    void showIdeas() const;

private:
    Brain* _brain;
};

#endif
