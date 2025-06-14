#include "../Inc/Dog.hpp"

Dog::Dog() {
    std::cout << "Dog -> default constructor called\n";
    this->type_ = "Dog";
    this->brain = new Brain;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    std::cout << "Dog -> copy constructor called\n";
    this->type_ = copy.type_;
    this->brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(const Dog &copy) {
    std::cout << "Dog -> assignment constructor called\n";
    if (this != &copy) {
        this->type_ = copy.type_;
        delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Dog -> is barking\n";
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "Dog -> destructor called\n";
}

std::string Dog::getBrainIdea(unsigned int index) const {
    return brain->getIdea(index);
}

void Dog::setBrainIdea(unsigned int index, const std::string &idea) {
    brain->setIdea(index, idea);
}
