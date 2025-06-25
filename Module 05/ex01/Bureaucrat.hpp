#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "./Form.hpp"

class Form;

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

        void signForm(Form &f);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj);

#endif

/*
Because GradeTooHighException by itself is just a type, not an object.

*/