#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal {
    protected:
        std::string type_;
    public:
        Animal();
        Animal(const Animal &copy);
        Animal& operator=(const Animal &copy);
        virtual ~Animal();

        virtual void makeSound() const = 0;

        void        setType(std::string &type);
        std::string getType() const ;
};

#endif
