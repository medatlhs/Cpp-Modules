#include "../Inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("undefined_type") {
    std::cout << "WrongAnimal -> default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal -> copy constructor called\n";
    this->type_ = copy.type_;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy) {
    std::cout << "WrongAnimal -> assign,ent constructor called\n";
    if (this != &copy)
        this->type_ = copy.type_;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal -> can't make a sound\n";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal -> destructor called\n";
}

void WrongAnimal::setType(std::string &type) {
    this->type_ = type;
}

std::string WrongAnimal::getType() const {
    return this->type_;
}
