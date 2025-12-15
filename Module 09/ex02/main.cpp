#include "PmergeMe.hpp" 

int main(int argc, char **argv)
{
    PmergeMe pmergeMe;
    try {
        std::vector<int> numbers = pmergeMe.parseInput(argc, argv);
        for (size_t i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    } catch(const std::exception& e) {
        return std::cerr << e.what() << std::endl, 1; 
    }

    return 0;
}
