
#include "../Includes/ScavTrap.hpp"

// int main() {
//     // ClapTrap charachter("lmlsdn");
//     // charachter.attack("lmhchach");
//     // charachter.takeDamage(8);
//     // charachter.attack("lmhchach");
//     // charachter.beRepaired(1);

//     std::string name = "RXZ1";
//     ScavTrap robot(name);
//     std::string name2 = "RXK2";
    
//     robot.attack(name2);

//     return 0;
// }

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

