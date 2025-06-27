#include "./Includes/AForm.hpp"
#include "./Includes/Bureaucrat.hpp"
#include "./Includes/PresidentialPardonForm.hpp"
#include "./Includes/ShrubberyCreationForm.hpp"
#include "./Includes/RobotomyRequestForm.hpp"
#include <iostream>


int main()
{
    try {
        Bureaucrat bureaucratA("bureaucratA", 150);
        PresidentialPardonForm pardonF("mojrim");

        std::cout << pardonF;

        pardonF.besigned(bureaucratA);
        bureaucratA.executeForm(pardonF);
    }
    catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    try {
        Bureaucrat bureaucratB("bureaucratB", 144);
        ShrubberyCreationForm shrubberyCreatingF("theZoo");

        std::cout << shrubberyCreatingF;

        shrubberyCreatingF.besigned(bureaucratB);
        shrubberyCreatingF.checkAndExecute(bureaucratB);
    } 
    catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat bureaucratC("bureaucratC", 46);
        RobotomyRequestForm robotmizeF("cat");

        std::cout << robotmizeF;
        bureaucratC.signForm(robotmizeF);
        bureaucratC.executeForm(robotmizeF);
    }
    catch(const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}
