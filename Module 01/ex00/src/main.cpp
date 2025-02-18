#include "../Includes/Zombie.hpp"

int main()
{
    Zombie *z = newZombie("zombie");
    z->announce();
    delete z;

    randomChump("zombie");
    return (0);
}
