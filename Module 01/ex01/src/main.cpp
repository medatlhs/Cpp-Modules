#include "../Includes/Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *z = zombieHorde(N, "zombie");
    for (int i = 0; i < N; i++) {
        z[i].announce();
    }
    delete[] z;
    return (0);
}
