#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    int i = 0;
    if (ac > 1) {
        while (av[++i]) {
            int j = -1;
            while (av[i][++j])
                std::cout << (char)toupper(av[i][j]);
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
