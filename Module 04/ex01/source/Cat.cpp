#include "../Inc/Cat.hpp"

Cat::Cat() {
    std::cout << "Cat -> default constructor called\n";
    this->type_ = "Cat";
    this->brain = new Brain();
    if (!this->brain) {
        std::cerr << "Allocation Failed!!\n";
        exit(1);
    }
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    std::cout << "Cat -> copy constructor called\n";
    this->type_ = copy.type_;
    this->brain = new Brain(*copy.brain);
    if (!this->brain) {
        std::cerr << "Allocation Failed!!\n";
        exit(1);
    }
}

Cat& Cat::operator=(const Cat &copy) {
    std::cout << "Cat -> assignment constructor called\n";
    if (this != &copy) {
        this->type_ = copy.type_;
        delete this->brain;
        this->brain = new Brain(*copy.brain);
        if (!this->brain) {
            std::cerr << "Allocation Failed!!\n";
            exit(1);
        }
    }
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Cat -> is meowing\n";
}

Cat::~Cat() {
    delete this->brain;
    std::cout << "Cat -> destructor called\n";
}

std::string Cat::getBrainIdea(unsigned int index) {
    return brain->getIdea(index);
}

void Cat::setBrainIdea(unsigned int index, const std::string &idea) {
    brain->setIdea(index, idea);
}
