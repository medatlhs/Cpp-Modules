#include "./easyfind.hpp"
#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i + 1);

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    } catch (const NotFoundException &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
