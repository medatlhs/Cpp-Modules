#include "../Includes/Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

void    Zombie::announce( void )
{
    std::cout << this->name << " :BraiiiiiiinnnzzzZ..." << std::endl;
}
