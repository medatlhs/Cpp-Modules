#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"
#include "./ClapTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(const std::string &_name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap& operator=(const DiamondTrap &other);
        ~DiamondTrap();

        void attack(const std::string& target);
        void whoAmI();
};

#endif
