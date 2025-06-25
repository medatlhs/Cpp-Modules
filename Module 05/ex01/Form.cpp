#include "Form.hpp"

Form::Form() 
    : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150) { }

Form::Form(std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)  {}

Form::Form(const Form &copy)
: _name(copy.get_Name()), _isSigned(false),
  _signGrade(copy.get_SignGrade()),
  _execGrade(copy.get_ExecGrade())
{
}

Form& Form::operator=(const Form& other) {
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

void Form::besigned(Bureaucrat &b) {
    if (b.getGrade() <= this->_signGrade)
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}

std::string Form::get_Name() const {
    return this->_name;
}

bool Form::check_Ifsigned() const {
    return this->_isSigned;
}

int Form::get_SignGrade() const {
    return this->_signGrade;
}

int Form::get_ExecGrade() const {
    return this->_execGrade;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade Too High !\n";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade Too Low !\n";
}
