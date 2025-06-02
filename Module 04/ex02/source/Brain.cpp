#include "../Inc/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain -> default constructor called\n";
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain -> copy constructor called\n";
    for (int index = 0; index < 100; index++)
        this->ideas[index] = copy.ideas[index];
}

Brain& Brain::operator=(const Brain &copy) {
    std::cout << "Brain -> assignment constructor called\n";
    if (this != &copy) {
        for (int index = 0; index < 100; index++)
            this->ideas[index] = copy.ideas[index];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain -> destructor called\n";
}

void Brain::setIdea(unsigned int index, const std::string &idea) {
    if (index < 100)
        this->ideas[index] = idea;
}

std::string Brain::getIdea(unsigned int index) const {
    if (index < 100)
        return this->ideas[index];
    return "";
}
