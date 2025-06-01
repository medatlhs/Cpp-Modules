#include "../Inc/WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat -> default constructor called\n";
    this->type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    std::cout << "WrongCat -> copy constructor called\n";
    this->type_ = copy.type_;
}

WrongCat& WrongCat::operator=(const WrongCat &copy) {
    std::cout << "WrongCat -> assignment constructor called\n";
    if (this != &copy)
        this->type_ = copy.type_;
    return *this;
}

void WrongCat::makeSound() const{
    std::cout << "WrongCat -> is meowing\n";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat -> destructor called\n";
}


