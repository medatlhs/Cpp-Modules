#pragma once 

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>
#include <ctime>
#include <stdexcept> 

class PmergeMe {
    private:
        int getJacobNumber(int n); 
        std::string trim(const std::string& number);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);  
        ~PmergeMe(); 
 
        std::vector<int> parseInput(int ac, char** av);

        template<typename T>
        void fordJohnsonSort(T& container); 
};

#include "PmergeMe.tpp"
