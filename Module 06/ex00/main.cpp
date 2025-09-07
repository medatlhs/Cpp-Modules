#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return std::cout << "Error: check number of arguments!\n", 1;

    try {
        ScalarConverter::convert(argv[1]);
    } catch(std::exception &e) {
        return std::cerr << e.what() << std::endl, 1;
    }

    return 0;
}
