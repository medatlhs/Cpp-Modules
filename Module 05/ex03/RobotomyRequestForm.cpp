#include "./Includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm::AForm("RobotomyRequestForm", 72, 45),_target("default_target") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm::AForm("RobotomyRequestForm", 72, 45),_target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    (void)executor;
    std::cout << "RobotomyRequestForm >> robotomizing " << this->_target << " : ZzZZZzzzzzzzzzzzz\n";

    std::srand(time(0));
    if (std::rand()%2==1)
        std::cout << "RobotomyRequestForm >> " <<  "Robotomizing " << this->_target << " succeed!\n";
    else
        std::cout << "RobotomyRequestForm >> " <<  "Robotomizing " << this->_target << " Failed!\n";
}
