#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        Form();
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &copy);
        Form& operator= (const Form &other);
        ~Form();
        
        void besigned(Bureaucrat &b);
        
        std::string get_Name() const;
        int get_SignGrade() const;
        int get_ExecGrade() const;
        bool check_Ifsigned() const;


        class GradeTooHighException: public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, Form& myobj);

#endif