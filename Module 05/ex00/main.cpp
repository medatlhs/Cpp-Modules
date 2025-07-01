#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    std::cout << "--- Valid Bureaucrat ---" << std::endl;
    try {
        Bureaucrat b1("BureaucratA", 42);
        std::cout << b1;

        b1.increment();
        std::cout << "after increment: " << b1;

        b1.decrement();
        b1.decrement();
        std::cout << "after two decrements: " << b1;
        
    } catch (const std::exception &e) {
        std::cout << "exception: " << e.what();
    }

    std::cout << "\n--- Grade Too High (constructor) ---" << std::endl;
    try {
        Bureaucrat b2("BureaucratB", 0);
    } catch (const std::exception &e) {
        std::cout << "exception: " << e.what();
    }

    std::cout << "\n--- grade too low (constructor) ---" << std::endl;
    try {
        Bureaucrat b3("BureaucratC", 151);
    } catch (const std::exception &e) {
        std::cout << "exception: " << e.what();
    }

    std::cout << "\n--- Incrementing beyond limit ---" << std::endl;
    try {
        Bureaucrat b4("BureaucratD", 1);
        std::cout << b4;
        b4.increment();
    } catch (const std::exception &e) {
        std::cout << "exception: " << e.what();
    }

    std::cout << "\n--- Decrementing beyond limit ---" << std::endl;
    try {
        Bureaucrat b5("BureaucratE", 150);
        std::cout << b5;
        b5.decrement();
    } catch (const std::exception &e) {
        std::cout << "exception: " << e.what();
    }

    return 0;
}
