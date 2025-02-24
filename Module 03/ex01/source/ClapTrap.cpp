#include "../Includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "claptrap ->  default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "claptrap ->  parameterized constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "claptrap ->  copy constructor called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap::~ClapTrap() {
    std::cout << "claptrap ->  destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "claptrap ->  assignment operator called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (!energyPoints || !hitPoints) {
        std::cout << "claptrap ->  " << this->name << " can't attack" << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "claptrap ->  " << this->name << " attacks " << target << ", causing " 
              << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!hitPoints) {
        std::cout << "claptrap ->  " << this->name << " is already dead\n";
        return ;
    }
    else if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "claptrap ->  " << name << " took " << amount << " points of damage. Remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!energyPoints || !hitPoints) {
        std::cout << "claptrap ->  " << this->name << " can't repair itself\n";
        return ;
    }
    energyPoints -= 1;
    hitPoints += amount;
    std::cout << "claptrap ->  " << name << " repaired itself: +" << amount << ", current HP: " << hitPoints << std::endl;
}
