#include "iter.hpp"
#include <iostream>

template<typename T>
void incrementElement(T &element) {
    element += 1;
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

    std::cout << "nonConst array before incrementing > ";
    ::iter(nonConstArray, size, printElement<int>);
    std::cout << std::endl;

    ::iter(nonConstArray, size, ::incrementElement<int>);
    std::cout << "nonConst array after incrementing  > ";
    ::iter(nonConstArray, size, ::printElement<int>);
    std::cout << std::endl;

    std::cout << "# Testing Const Array #" << std::endl;
    size = sizeof(constArray)/sizeof(int);
    std::cout << "printed elements: ";
    ::iter(constArray, size, ::printElement<int>);
    std::cout << std::endl;

    return 0;
}

// So, what is the fix?

// The "fix" isn't to prevent a compiler error from happening in an invalid case. 
// The fix is to provide a single, correct iter template that correctly handles all valid cases, 
// letting the compiler flag the invalid ones (like passing a const array to a non-const function). 
// The exercise is a test of your understanding of how C++ templates and const correctness work together, 
// not about forcing an invalid operation to succeed.
