#include "PmergeMe.hpp"

template<typename T>
void PmergeMe::fordJohnsonSort(T& container) { 
    if (container.size() <= 1)
        return ;
    
    struggler = -1; 
    if (container.size() % 2 != 0) {
        struggler = container.back();
        container.pop_back(); 
    }

    for (size_t i = 0; i < numbers.size(); i += 2) {
        if (numbers[i] > numbers[i + 1])
            pairedNumbers.push_back(std::make_pair(numbers[i], numbers[i + 1]));
        else
            pairedNumbers.push_back(std::make_pair(numbers[i + 1], numbers[i]));
    }

    std::vector<int> firstElements;
    for (size_t i = 0; i < pairedNumbers.size(); ++i) {
        firstElements.push_back(pairedNumbers[i].first);
    
    fordJohnsonSort(firstElements);
}
