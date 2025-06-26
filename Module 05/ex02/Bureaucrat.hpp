#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "./AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator= (const Bureaucrat& other);
        ~Bureaucrat();

        class GradeTooHighException: public std::exception {
            public:
               const char *what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                const char *what() const throw();
        };

        std::string getName() const;
        int         getGrade() const;

        void increment();
        void decrement();

        void signForm(AForm &f);
        void executeForm(const AForm &form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj);

#endif

/*
Because GradeTooHighException by itself is just a type, not an object.

*/