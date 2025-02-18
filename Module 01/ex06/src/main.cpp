#include "../Includes/Harl.hpp"

int getExpression(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
        if (level == levels[i])
            return i;
    return -1;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Invalid number of arguments\n";
        return 1;
    }
    Harl harl;
    switch (getExpression(av[1]))
    {
    case 0:
        harl.complain("debug");
    case 1:
        harl.complain("info");
    case 2:
        harl.complain("warning");
    case 3:
        harl.complain("error");
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
    return 0;
}
