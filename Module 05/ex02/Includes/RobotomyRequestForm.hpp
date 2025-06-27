#ifndef ROBOTOMYREQUEST_HPP
#define ROBOTOMYREQUEST_HPP

#include "AForm.hpp"
#include <string>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;
};

#endif
