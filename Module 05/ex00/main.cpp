#include "Bureaucrat.hpp"
#include <iostream>

int main() {

    std::cout << "--- valid bureaucrat ---" << std::endl;
    try {
        Bureaucrat b1("youssef", 42);
        std::cout << b1;

        b1.increment();
        std::cout << "after increment: " << b1;

        b1.decrement();
        b1.decrement();
        std::cout << "after two decrements: " << b1;
        
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what();
    }

    std::cout << "\n--- grade too high (constructor) ---" << std::endl;
    try {
        Bureaucrat b2("oussama", 0);
    } catch (const std::exception &e) {
        std::cerr << "exception: " << e.what();
    }

    std::cout << "\n--- grade too low (constructor) ---" << std::endl;
    try {
        Bureaucrat b3("naser", 151);
    } catch (const std::exception &e) {
        std::cerr << "exception: " << e.what();
    }

    std::cout << "\n--- Incrementing beyond limit ---" << std::endl;
    try {
        Bureaucrat b4("lmlsdn", 1);
        std::cout << b4;
        b4.increment();
    } catch (const std::exception &e) {
        std::cerr << "exception: " << e.what();
    }

    std::cout << "\n--- Decrementing beyond limit ---" << std::endl;
    try {
        Bureaucrat b5("yassine", 150);
        std::cout << b5;
        b5.decrement();
    } catch (const std::exception &e) {
        std::cerr << "exception: " << e.what();
    }

    return 0;
}
