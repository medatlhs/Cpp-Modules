#include "./ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap ->  default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap ->  parametrized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap ->  copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap ->  assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ScavTrap::ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap ->  destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    if (energyPoints < 1 || hitPoints < 1) {
        std::cout << "ScavTrap ->  " << this->name << " can't attack" << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "ScavTrap ->  " << this->name << " attacks " << target << ", causing " 
              << this->attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap ->  " << this->name << " is now in Gate keeper mode" << std::endl;
}
