#include "../Inc/Animal.hpp"

Animal::Animal() : type("default") {
    std::cout << "Animal -> default constructor called\n";
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal -> copy constructor called\n";
    this->type = copy.type;
}

Animal& Animal::operator=(const Animal &copy) {
    std::cout << "Animal -> assign,ent constructor called\n";
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal -> making a sound\n";
}

Animal::~Animal() {
    std::cout << "Animal -> destructor called\n";
}

