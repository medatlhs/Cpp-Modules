#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Dog: public Animal {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog& operator=(const Dog &copy);
        ~Dog();

        void makeSound() const;

        void setBrainIdea(unsigned int index, const std::string &idea);
        std::string getBrainIdea(unsigned int index) const ;
};

#endif