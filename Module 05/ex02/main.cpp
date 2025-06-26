#include "./Includes/AForm.hpp"
#include "./Includes/Bureaucrat.hpp"
#include "./Includes/PresidentialPardonForm.hpp"
#include "./Includes/ShrubberyCreationForm.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    try {
        Bureaucrat bureaucrat_A("bureaucrat_A", 150);
        PresidentialPardonForm form_A("oussamaBeladen");

        std::cout << form_A;
        form_A.besigned(bureaucrat_A);
        bureaucrat_A.executeForm(form_A);
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try {
        Bureaucrat Bureaucrat_A("Bure", 150);
        ShrubberyCreationForm ShrubberyCreationForm_A("zoo");

        ShrubberyCreationForm_A.besigned(Bureaucrat_A);
        ShrubberyCreationForm_A.checkAndExecute(Bureaucrat_A);
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    srand(time(NULL));
    std::cout << rand();
    return 0;
}
