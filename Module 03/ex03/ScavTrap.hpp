#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        static const int hit_points_ = 100;
        static const int energy_points_ = 50;
        static const int attack_damage_ = 20;

        void attack(const std::string& target);
        void guardGate();
};

#endif
