#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { } 

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this; 
}

PmergeMe::~PmergeMe() { }

std::string PmergeMe::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos || last == std::string::npos)
        return ""; 
    return str.substr(first, last - first + 1);
}
// hey copilot add the ability to accept "+123" or "    +123  " as valid input
std::vector<int> PmergeMe::parseInput(int ac, char** av)
{
    std::vector<int> numbers;
    if (ac < 2)
        throw std::invalid_argument("Error: No arguments provided");
    for (int i = 1; i < ac; ++i) {
        std::string number(av[i]);
        std::string trimmedNum = trim(number);
        if (trimmedNum.empty())
            throw std::invalid_argument("Error: Empty argument");
        for (size_t j = 0; j < trimmedNum.length(); ++j) {
            if (j == 0 && (trimmedNum[j] == '+'))
                continue;
            if (!isdigit(trimmedNum[j]))
                throw std::invalid_argument("Error: Not valid number");
        } 
        std::stringstream ss(trimmedNum);
        long num;
        ss >> num;
        if (ss.fail() || !ss.eof())
            throw std::invalid_argument("Error: Not valid number");
        if (num > INT_MAX)
            throw std::out_of_range("Error: Too large number");
        numbers.push_back(static_cast<int>(num));
    }
    return numbers; 
}


int PmergeMe::getJacobNumber(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int jacobTwoBefore = 0;
    int jacobOneBefore = 1;
    int result = 0; 

    for (int currentIndex = 2; currentIndex <= n; ++currentIndex) {
        result = jacobOneBefore + 2 * jacobTwoBefore;
        jacobTwoBefore = jacobOneBefore;
        jacobOneBefore = result;
    }
    return result;
}

