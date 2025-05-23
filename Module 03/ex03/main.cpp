#include "./DiamondTrap.hpp"


int main() {

    std::cout << "--- constructring ROBOT-A ---\n";
    DiamondTrap robot_1("ROBOT-A");
    robot_1.whoAmI();
    robot_1.attack("Enemy-A");
    robot_1.takeDamage(11);
    robot_1.beRepaired(22);
    robot_1.highFivesGuys();

    std::cout << "--- copy constructor test ---\n";
    DiamondTrap robot_2(robot_1);
    robot_2.attack("Enemy-B");
    robot_2.whoAmI();

    std::cout << "--- Assignment constructor test ---\n";
    DiamondTrap robot_3("ROBOT-C");
    robot_3 = robot_2;
    robot_3.whoAmI();

    std::cout << "--- destrcutor logs ---\n";

    return 0;
}
