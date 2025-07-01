#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("someBureaucrat"), _grade(150) { }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this == &other)
        return *this;
    this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() { }

std::string Bureaucrat::getName() const {
    return _name;
}

void Bureaucrat::signForm(Form &f) {
    f.beSigned(*this);
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::increment() {
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade -= 1;
}

void Bureaucrat::decrement() {
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Bureaucrat >> Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Bureaucrat >> Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &obj) {
    out << "Bureaucrat >> " << "name: " << obj.getName() << ", grade: " 
        << obj.getGrade() << std::endl;
    return out;
}
