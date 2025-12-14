#include "RPN.hpp"

int main(int argc, char** argv) {
    if (argc != 2)
        return std::cerr << "Error: Invalid number of arguments." << std::endl, 1;

    RPN calculator;
    try {
        int result = calculator.calculate(argv[1]);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        return std::cerr << e.what() << std::endl, 1;
    }
    return 0;
}   