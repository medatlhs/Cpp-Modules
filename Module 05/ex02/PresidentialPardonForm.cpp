#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm::AForm("PresidentialPardonForm", 25, 5),_target("default") { }

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm::AForm("PresidentialPardonForm", 25, 5),_target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    std::cout << "PresidentialPardonForm >> " << this->_target 
              << " has been pardoned by Zafod Beeblebrox --"
              << executor.getName() << " sucessfully executed "
              << this->get_Name() <<  std::endl;
}
