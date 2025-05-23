#include "./FragTrap.hpp"

int main(void)
{
	FragTrap scav("FRAGY");

	scav.attack("Enemy-B");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.highFivesGuys();

	return (0);
}
