#include "whatever.hpp"
#include <iostream>
#include <string>

int main(void)
{
    char c1 = 'x', c2 = 'y';
    int i1 = 42, i2 = 7;
    double d1 = 3.14, d2 = 2.71;
    std::string str1 = "hello", str2 = "world";

    std::cout << "Before swap:\n";
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << "\n";
    std::cout << "i1 = " << i1 << ", i2 = " << i2 << "\n";
    std::cout << "d1 = " << d1 << ", d2 = " << d2 << "\n";
    std::cout << "str1 = " << str1 << ", str2 = " << str2 << "\n\n";

    ::swap(c1, c2);
    ::swap(i1, i2);
    ::swap(d1, d2);
    ::swap(str1, str2);

    std::cout << "After swap:\n";
    std::cout << "c1 = " << c1 << ", c2 = " << c2 << "\n";
    std::cout << "i1 = " << i1 << ", i2 = " << i2 << "\n";
    std::cout << "d1 = " << d1 << ", d2 = " << d2 << "\n";
    std::cout << "str1 = " << str1 << ", str2 = " << str2 << "\n\n";

    std::cout << "Min and Max:\n";
    std::cout << "min(c1, c2) = " << ::min(c1, c2) << ", max(c1, c2) = " << ::max(c1, c2) << "\n";
    std::cout << "min(i1, i2) = " << ::min(i1, i2) << ", max(i1, i2) = " << ::max(i1, i2) << "\n";
    std::cout << "min(d1, d2) = " << ::min(d1, d2) << ", max(d1, d2) = " << ::max(d1, d2) << "\n";
    std::cout << "min(str1, str2) = " << ::min(str1, str2) << ", max(str1, str2) = " << ::max(str1, str2) << "\n";

    return 0;
}
