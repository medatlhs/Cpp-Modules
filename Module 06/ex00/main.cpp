#include "ScalarConverter.hpp"
#include <cmath>   // for std::nan, std::numeric_limits
#include <limits>

int main(int argc, char const *argv[])
{
    // std::cout << "runing...\n";
    if (argc != 2)
        return  std::cout << "Error: check number of arguments!\n", 1;
    std::string input = argv[1];
    ScalarConverter::convert(input);
    return (0);
}
