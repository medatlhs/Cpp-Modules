#pragma once 


#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
    private:
        std::vector< std::pair<int, int> > pairedNumbers;
        int   struggler;
    
        // utils 
        std::string trim(const std::string& number);
        void        pairNumbers(std::vector<int>& numbers);
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