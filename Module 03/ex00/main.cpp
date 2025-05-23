#include "./ClapTrap.hpp"

int main() {
    ClapTrap robot("ROBOT-A");

    robot.attack("ENEMY-B");
    robot.takeDamage(4);
    robot.attack("ENEMY-C");
    robot.beRepaired(2);
    robot.takeDamage(8);      
    robot.attack("ENEMY-D");    
    robot.beRepaired(5);   

    return 0;
}
