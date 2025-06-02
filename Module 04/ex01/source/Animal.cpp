#include "../Inc/Animal.hpp"

Animal::Animal() : type_("undefined_type") {
    std::cout << "Animal -> default constructor called\n";
}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal -> copy constructor called\n";
    this->type_ = copy.type_;
}

Animal& Animal::operator=(const Animal &copy) {
    std::cout << "Animal -> assign,ent constructor called\n";
    if (this != &copy)
        this->type_ = copy.type_;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal -> can't make a sound \n";
}

Animal::~Animal() {
    std::cout << "Animal -> destructor called\n";
}

void Animal::setType(std::string &type) {
    this->type_ = type;
}

std::string Animal::getType() const {
    return this->type_;
}
