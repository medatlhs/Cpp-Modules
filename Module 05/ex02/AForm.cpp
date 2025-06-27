#include "./Includes/AForm.hpp"
#include "./Includes/Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150) 
{ 
}

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    else if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &copy)
    : _name(copy.get_Name()), _isSigned(false), 
      _signGrade(copy.get_SignGrade()), _execGrade(copy.get_ExecGrade())
{

}

AForm& AForm::operator=(const AForm& other) {
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

void AForm::besigned(Bureaucrat &b) {
    if (b.getGrade() <= this->_signGrade) {
        this->_isSigned = true;
        std::cout << b.getName() << " signed " << this->_name << std::endl;
    }
    else {
        std::cout << b.getName()
                  << " coudn't sign " << this->_name
                  << std::endl;
        throw GradeTooLowException();
    }
}

void AForm::checkAndExecute(Bureaucrat const &executor) const {
    if (!this->_isSigned) {
        std::cout << "can't execute " << this->_name << ", Form not signed.\n";
        throw FormNotSignedException();
    }
    else if (executor.getGrade() > this->_execGrade) {
        std::cout << "bureaucrat can't execute " << this->_name << std::endl;
        throw GradeTooLowException();
    }
    this->execute(executor);
}

std::string AForm::get_Name() const {
    return this->_name;
}

bool AForm::check_Ifsigned() const {
    return this->_isSigned;
}

int AForm::get_SignGrade() const {
    return this->_signGrade;
}

int AForm::get_ExecGrade() const {
    return this->_execGrade;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Bureaucrat Grade Too High!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Bureaucrat Grade Too Low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

std::ostream& operator<<(std::ostream& out, AForm& myobj) {
    std::cout << "# " << myobj.get_Name() 
              << " info: signed: " << (myobj.check_Ifsigned() == 1 ? "true" : "false")
              << ", to sign grade: " << myobj.get_SignGrade()
              << ", execution grade: " << myobj.get_ExecGrade()
              << std::endl;
    return out;
}
