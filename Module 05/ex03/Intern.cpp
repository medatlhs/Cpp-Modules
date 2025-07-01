#include "./Includes/Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm* makeRobotomyRequest(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* makeShrubberyCreation(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* makePresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string &form_name, const std::string &form_target) {
   
    std::string form_names[] = 
        {"robotomy request", "presidential pardon", "shrubbery creation"};
    AForm* (*makers[])(const std::string &target) = 
        { makeRobotomyRequest, makePresidentialPardonForm, makeShrubberyCreation };

    int size = sizeof(makers) / sizeof(makers[0]);
    for(int i = 0; i < size; i++) {
        if (form_name == form_names[i]) {
            std::cout << "Intern creates " << form_name << " Form\n";
            return makers[i](form_target);
        }
    }
    throw std::invalid_argument("Bad args: Form name does not exist!");
}
