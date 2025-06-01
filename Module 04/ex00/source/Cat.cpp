#include "../Inc/Cat.hpp"

Cat::Cat() {
    std::cout << "Cat -> default constructor called\n";
    this->type = "zoro_cat";
}

Cat::Cat(const Cat &copy) {
    std::cout << "Cat -> copy constructor called\n";
    this->type = copy.type;
}

Cat& Cat::operator=(const Cat &copy) {
    std::cout << "Cat -> assignment constructor called\n";
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat -> saying wsup man\n";
}

Cat::~Cat() {
    std::cout << "Cat -> destructor called\n";
}

