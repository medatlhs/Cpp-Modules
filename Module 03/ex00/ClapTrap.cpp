#include "./ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "parameterized constructor got called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "copy constructor called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "assignment operator called" << std::endl;
    if (this != &other ) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (!energyPoints || !hitPoints) {
        std::cout << "-> " << this->name << " can't attack" << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "-> " << this->name << " attacks " << target << ", causing " 
              << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (!hitPoints) {
        std::cout << "-> " << this->name << " is already dead 💀\n";
        return ;
    }
    else if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;
    std::cout << "-> " << name << " took " << amount << " points of damage. Remaining HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!energyPoints || !hitPoints) {
        std::cout << "-> " << this->name << " is too damaged or exhausted to repair itself.\n";
        return ;
    }
    this->energyPoints -= 1;
    hitPoints += amount;
    std::cout << "-> " << name << " repaired itself: +" << amount << ", current HP: " << hitPoints << std::endl;
}
