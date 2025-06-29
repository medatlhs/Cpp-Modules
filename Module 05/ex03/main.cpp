#include "./Includes/AForm.hpp"
#include "./Includes/Bureaucrat.hpp"
#include "./Includes/PresidentialPardonForm.hpp"
#include "./Includes/ShrubberyCreationForm.hpp"
#include "./Includes/RobotomyRequestForm.hpp"
#include "./Includes/Intern.hpp"


int main() {
    try {
        Bureaucrat  bureaucratA("bureaucratA", 1);
        Intern      someIntern;

        std::cout << "\n--- Testing Robotomy Request ---\n";
        AForm *robotomyForm = someIntern.makeForm("robotomy request", "Bender");
        robotomyForm->besigned(bureaucratA);
        robotomyForm->checkAndExecute(bureaucratA);
        delete robotomyForm;

        std::cout << "\n--- Testing Presidential Pardon ---\n";
        AForm *pardonForm = someIntern.makeForm("presidential pardon", "prisoner");
        pardonForm->besigned(bureaucratA);
        pardonForm->checkAndExecute(bureaucratA);
        delete pardonForm;

        std::cout << "\n--- Testing Shrubbery Creation ---\n";
        AForm *shrubberyForm = someIntern.makeForm("shrubbery creation", "garden");
        shrubberyForm->besigned(bureaucratA);
        shrubberyForm->checkAndExecute(bureaucratA);
        delete shrubberyForm;

        std::cout << "\n--- Testing Invalid Form ---\n";
        AForm *badForm = someIntern.makeForm("invalid form", "nothing");
        std::cout << "here\n";
        delete badForm; // will throw

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}