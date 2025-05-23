
#include "ScavTrap.hpp"

int main() {

    ScavTrap scav("Robto-A");

    scav.attack("Enemy-B");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();

    return 0;
}
