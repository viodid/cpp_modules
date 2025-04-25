#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& obj);
    ~FragTrap();
    FragTrap& operator=(const FragTrap& obj);

    void attack(const std::string& target);
    void highFivesGuys() const;
};

#endif
