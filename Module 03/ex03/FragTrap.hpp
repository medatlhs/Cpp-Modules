#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& target);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        static const int hit_points_ = 100;
        static const int energy_points_ = 100;
        static const int attack_damage_ = 30;

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
