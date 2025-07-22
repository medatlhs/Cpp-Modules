#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "runing...\n";
    if (argc != 2)
        return  std::cout << "Error: check number of arguments!\n", 1;
    
    std::string input = argv[1];
    ScalarConverter::convert(input);
    return 0;
}
