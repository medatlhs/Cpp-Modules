#include "./Includes/ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm::AForm("ShrubberyCreationForm", 145, 137),_target("default_target") { }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm::AForm("ShrubberyCreationForm", 145, 137),_target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

    std::string fileName = this->_target + "_shrubbery";
    std::ofstream outfile(fileName.c_str());

    if (!outfile.is_open()) {
        throw std::runtime_error("ShrubberyCreationForm >> Error opening outfile!");
    }
    
    outfile << "       v\n";
    outfile << "      >X<\n";
    outfile << "       A\n";
    outfile << "      d$b\n";
    outfile << "    .d\\$$b.\n";
    outfile << "  .d$i$$\\$$b.\n";
    outfile << "     d$$@b\n";
    outfile << "    d\\$$$ib\n";
    outfile << "  .d$$$\\$$$b\n";
    outfile << ".d$$@$$$$\\$$ib.\n";
    outfile << "      ###\n";
    outfile << "      ###\n";
    outfile << "      ###\n";

    outfile.close();
    std::cout << "ShrubberyCreationForm >> " << executor.getName() << " sucessfully executed " 
              << this->get_Name() <<  std::endl;
}
