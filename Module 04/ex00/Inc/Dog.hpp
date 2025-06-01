#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"

class Dog: public Animal {
    private:
        std::string type;
    public:
        Dog();
        Dog(const Dog &copy);
        Dog& operator=(const Dog &copy);
        ~Dog();

        void makeSound() const;
};

#endif