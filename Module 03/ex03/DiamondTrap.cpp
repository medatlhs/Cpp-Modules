#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : name("default_") {
    std::cout << "DimaondTrap ->  default constructor called\n";
    this->hitPoints = FragTrap::hit_points_;
    this->energyPoints = ScavTrap::energy_points_;
    this->attackDamage = FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), name(name) {
    std::cout << "DimaondTrap ->  parameterized constructor called\n";
    this->hitPoints = FragTrap::hit_points_;
    this->energyPoints = ScavTrap::energy_points_;
    this->attackDamage = FragTrap::attack_damage_;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap ->  copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap ->  assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
        this->ClapTrap::name = other.ClapTrap::name;
    }
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap ->  this->name is: '" << this->name 
              << "' and ClapTrap name is: '" << ClapTrap::name << "'\n";
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap ->  destructor called" << std::endl;
}

