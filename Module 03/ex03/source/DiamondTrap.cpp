#include "../Includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("default") {
    std::cout << "DimaondTrap ->  default constructor called\n";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DimaondTrap ->  copy constructor called\n";
    ClapTrap::name =  name + "_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {

    }
    return *this;
}

DiamondTrap::~DiamondTrap() {

}
