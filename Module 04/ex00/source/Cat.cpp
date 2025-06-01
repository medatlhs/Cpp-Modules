#include "../Inc/Cat.hpp"

Cat::Cat() {
    std::cout << "Cat -> default constructor called\n";
    this->type_ = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat -> copy constructor called\n";
    this->type_ = copy.type_;
}

Cat& Cat::operator=(const Cat &copy) {
    std::cout << "Cat -> assignment constructor called\n";
    if (this != &copy)
        this->type_ = copy.type_;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat -> is meowing\n";
}

Cat::~Cat() {
    std::cout << "Cat -> destructor called\n";
}

