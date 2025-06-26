#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        // Bureaucrat with highest rank
        Bureaucrat bureaucrat_A("bureaucrat_A", 150);

        // Create a Presidential Pardon Form for a target
        PresidentialPardonForm form_A("oussamaBeladen");

        // Bureaucrat signs the form
        // form_A.besigned(bureaucrat_A);

        // Bureaucrat executes the form
        bureaucrat_A.executeForm(form_A);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}
