#include "../Includes/ScavTrap.hpp"

int main(void)
{
	std::cout << "-------------Creating ClapTrap-------------" << std::endl;
	ClapTrap clap("Clappy");

	std::cout << "-------------Creating ScavTrap-------------" << std::endl;
	ScavTrap scav("Scavvy");

	std::cout << "-------------actions-----------------------" << std::endl;
	clap.attack("Enemy");

	scav.attack("Enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << "--------------Destructors-------------------" << std::endl;

	return (0);
}
