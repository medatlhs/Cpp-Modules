#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;

    public:
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &copy);
        AForm& operator= (const AForm &other);
        virtual ~AForm();
        
        void besigned(Bureaucrat &b);
        void checkAndExecute(Bureaucrat const &executor) const;
        virtual void execute(Bureaucrat const &executor) const = 0;

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

        class FormNotSignedException: public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, AForm& myobj);

#endif