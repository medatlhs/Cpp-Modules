#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) 
    : _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) 
    : _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
    : _name(other._name) 
{
    if (this == &other)
        return *this;
    this->_grade = other._grade;
    return *this;
}
