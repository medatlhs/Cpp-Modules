#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap ->  default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& _name) : ClapTrap(_name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap ->  parametrized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap ->  copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "FragTrap ->  assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap ->  destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
    if (!energyPoints || !hitPoints) {
        std::cout << "FragTrap ->  " << this->name << " can't attack" << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "FragTrap ->  " << this->name << " attacks " << target << ", causing " 
              << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap ->  " << this->name << " wants a high five 🖐️" << std::endl;
}
