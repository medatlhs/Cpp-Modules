#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {

public:
    Intern();
    Intern(const std::string &target);
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    
    AForm* makeForm(std::string formName, std::string formTarget);
};

#endif