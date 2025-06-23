#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
    private:
        std::string _name;
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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj);

#endif