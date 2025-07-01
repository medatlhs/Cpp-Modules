#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("someForm"), _isSigned(false), _signGrade(150), _execGrade(150) { }

Form::Form(std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &copy): 
    _name(copy.get_Name()), _isSigned(false),  _signGrade(copy.get_SignGrade()), _execGrade(copy.get_ExecGrade()) { }

Form& Form::operator=(const Form& other) {
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}

Form::~Form() { }

void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->_signGrade) {
        this->_isSigned = true;
        std::cout << "Form >> " << "Bureaucrat: " << b.getName()
                  << " sucessfully signed " << this->_name
                  << std::endl;
    }
    else {
        std::cout << "Form >> " << "Bureaucrat: " << b.getName()
                  << " coudn't sign " << this->_name
                  << std::endl;
        throw GradeTooLowException();
    }
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
    return "Form >> Grade Too High!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form >> Grade Too Low!";
}

std::ostream& operator<<(std::ostream& out, Form& myobj) {
    std::cout << "Form >> " << myobj.get_Name() 
              << "; is signed: " << (myobj.check_Ifsigned() == 1 ? "true" : "false")
              << "; to sign grade: " << myobj.get_SignGrade()
              << "; execution grade: " << myobj.get_ExecGrade()
              << std::endl;
    return out;
}
