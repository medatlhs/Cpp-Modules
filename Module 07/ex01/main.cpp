#include "iter.hpp"
#include <iostream>

template<typename T>
void incrementElement(T &element) {
    element++;
}

template<typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

int main(void)
{
    int nonConstArray[] = {14, 52, 365, 445, 65};
    const int constArray[] = {1, 2, 3, 4, 5};

    std::cout << "# Testing NonConst Array #" << std::endl;
    size_t size = sizeof(nonConstArray)/sizeof(int);

    std::cout << "nonConst array before incrementing: ";
    ::iter(nonConstArray, size, ::printElement<int>);
    std::cout << std::endl;

    ::iter(nonConstArray, size, ::incrementElement<int>);

    std::cout << "nonConst array after incrementing: ";
    ::iter(nonConstArray, size, ::printElement<int>);
    std::cout << std::endl;

    std::cout << "# Testing Const Array #" << std::endl;
    size = sizeof(constArray)/sizeof(int);
    std::cout << "printed elements: ";
    ::iter(constArray, size, ::printElement<int>);
    std::cout << std::endl;

    return 0;
}
