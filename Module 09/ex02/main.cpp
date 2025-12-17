#include "PmergeMe.hpp" 

int main(int argc, char **argv)
{
    PmergeMe            pmergeMe;
    std::vector<int>    vec;
    std::deque<int>     deq;

    try {
        vec = pmergeMe.parseInput(argc, argv);
        deq.insert(deq.end(), vec.begin(), vec.end()); 
    } catch(const std::exception& e) {
        return std::cerr << e.what() << std::endl, 1;
    }

    std::cout << "Before : ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    clock_t start = clock();
    pmergeMe.fordJohnsonSort(vec);
    clock_t end = clock();
    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "After  : ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : "
              << time << " us" << std::endl;

    start = clock();
    pmergeMe.fordJohnsonSort(deq);
    end = clock();
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
 
    std::cout << "Time to process a range of " << deq.size() 
              << " elements with std::deque  : " 
              << time << " us" << std::endl;
    return 0;
}
