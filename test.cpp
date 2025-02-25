#include <iostream>

class ClapTrap {
public:
    ClapTrap() {
        std::cout << "ClapTrap Constructor" << std::endl;
        clapTrapData = 10;
    }
    ClapTrap(const ClapTrap& other) {
        std::cout << "ClapTrap Copy Constructor" << std::endl;
        clapTrapData = other.clapTrapData;
    }

    int clapTrapData;
};

class ScavTrap : virtual public ClapTrap { // Virtual inheritance
public:
    ScavTrap() {
        std::cout << "ScavTrap Constructor" << std::endl;
        scavTrapData = 20;
    }
    ScavTrap(const ScavTrap& other) : ClapTrap(other) {
        std::cout << "ScavTrap Copy Constructor" << std::endl;
        scavTrapData = other.scavTrapData;
    }
    int scavTrapData;
};

class FragTrap : virtual public ClapTrap { // Virtual inheritance
public:
    FragTrap() {
        std::cout << "FragTrap Constructor" << std::endl;
        fragTrapData = 30;
    }
    FragTrap(const FragTrap& other) : ClapTrap(other) {
        std::cout << "FragTrap Copy Constructor" << std::endl;
        fragTrapData = other.fragTrapData;
    }
    int fragTrapData;
};

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap() {
        std::cout << "DiamondTrap Constructor" << std::endl;
        diamondTrapData = 40;
    }

    DiamondTrap(const DiamondTrap& other) {
        std::cout << "DiamondTrap Copy Constructor" << std::endl;
        diamondTrapData = other.diamondTrapData;
    }

    void printData() {
        std::cout << "DiamondTrap Data:" << std::endl;
        std::cout << "  ClapTrap Data: " << ClapTrap::clapTrapData << std::endl;
        std::cout << "  ScavTrap Data: " << scavTrapData << std::endl;
        std::cout << "  FragTrap Data: " << fragTrapData << std::endl;
        std::cout << "  DiamondTrap Data: " << diamondTrapData << std::endl;
    }

    int diamondTrapData;
};

int main() {
    DiamondTrap original;
    original.printData();
    std::cout << std::endl;

    DiamondTrap copy = original;
    copy.printData();

    return 0;
}