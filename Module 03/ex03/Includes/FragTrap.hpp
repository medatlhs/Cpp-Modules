#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../Includes/ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& target);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif
