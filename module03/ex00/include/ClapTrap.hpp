#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <iostream>
#include <ostream>
#include <string>

class ClapTrap {
public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& obj);
    ~ClapTrap();
    ClapTrap& operator=(const ClapTrap& obj);

    int getAttackDamage() const;
    int getHitPoints() const;
    int getEnergPoints() const;
    std::string getName() const;

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void decreaseEnergy();

private:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
};

#endif
