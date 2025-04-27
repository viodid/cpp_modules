#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : public AMateria {
protected:
    Cure(const Cure& obj);
    Cure& operator=(const Cure& obj);

public:
    Cure();
    ~Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
