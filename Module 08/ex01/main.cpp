#include "./Span.hpp"
#include <iostream>
#include <list>
#include <deque>
#include <set>

int main()
{
    std::cout << "----- Provided Test -----" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "----- MyOwn Test -----" << std::endl;

    int n = 10000; 
    std::vector<int> numbers;
    for (int i = 0; i < n; ++i)
        numbers.push_back(i + 1);
    
    Span sp2 = Span(n);
    sp2.addNumber(numbers.begin(), numbers.end());
    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span : " << sp2.longestSpan() << std::endl;

    std::cout << "----- Exception Test -----" << std::endl;
    try {
        sp2.addNumber(42);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    Span sp3 = Span(1);
    sp3.addNumber(1);
    try {
        sp3.shortestSpan();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
