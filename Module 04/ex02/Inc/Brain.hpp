#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "./Animal.hpp"

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &copy);
        Brain& operator=(const Brain &copy);
        ~Brain();

        void setIdea(unsigned int index, const std::string &idea);
        std::string getIdea(unsigned int index) const ;
};

#endif
