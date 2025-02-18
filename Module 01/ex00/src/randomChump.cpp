#include "../Includes/Zombie.hpp"

void randomChump( std::string name )
{
    Zombie z(name);
    z.announce();
}
