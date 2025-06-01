#include "../Inc/Dog.hpp"

Dog::Dog() {
    std::cout << "Dog -> default constructor called\n";
    this->type = "dog_";
}

Dog::Dog(const Dog &copy) {
    std::cout << "Dog -> copy constructor called\n";
    this->type = copy.type;
}

Dog& Dog::operator=(const Dog &copy) {
    std::cout << "Dog -> assignment constructor called\n";
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog -> is barking\n";
}

Dog::~Dog() {
    std::cout << "Dog -> destructor called\n";
}