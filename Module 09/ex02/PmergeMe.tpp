#include "PmergeMe.hpp"
#include <algorithm> 

template<typename T>
void PmergeMe::fordJohnsonSort(T& container)
{
    if (container.size() <= 1)
        return ;

    int struggler = -1; 
    if ((container.size() % 2) != 0) {
        struggler = container.back();
        container.pop_back(); 
    }

    std::vector< std::pair<int, int> > pairedNumbers;
    for (size_t i = 0; i < container.size(); i += 2) {
        if (container[i] < container[i + 1])
            pairedNumbers.push_back(std::make_pair(container[i], container[i + 1]));
        else
            pairedNumbers.push_back(std::make_pair(container[i + 1], container[i]));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairedNumbers.size(); i++)
        mainChain.push_back(pairedNumbers[i].second);

    fordJohnsonSort(mainChain);
    
    std::vector<std::pair<int, int> > pendChain; 

    for (size_t i = 0; i < mainChain.size(); i++) {
        for (size_t j = 0; j < pairedNumbers.size(); j++) {
            if (mainChain[i] == pairedNumbers[j].second) {
                pendChain.push_back(pairedNumbers[j]);
                break ;
            }
        }
    }

    mainChain.insert(mainChain.begin(), pendChain[0].first);  

    size_t insertedNumbers = 1;
    size_t index = 3;
    size_t pendSize = pendChain.size();
    while (insertedNumbers < pendSize) {
        size_t start = getJacobNumber(index - 1);
        size_t end = getJacobNumber(index);

        if (end > pendSize)
            end = pendSize;
        for (size_t i = (end - 1); i >= start; i--) {

            size_t numberToInsert = pendChain[i].first;
            std::vector<int>::iterator largestPos;
            largestPos = std::find(mainChain.begin(), mainChain.end(), pendChain[i].second);
            std::vector<int>::iterator insertPos;
            insertPos = std::upper_bound(mainChain.begin(), largestPos, numberToInsert);
            mainChain.insert(insertPos, numberToInsert);
            insertedNumbers++;
        }
        index++;
    }

    if (struggler != -1) {
        std::vector<int>::iterator pos;
        pos = std::upper_bound(mainChain.begin(), mainChain.end(), struggler);
        mainChain.insert(pos, struggler);
    }
    container.clear();
    container.insert(container.end(), mainChain.begin(), mainChain.end());
}


