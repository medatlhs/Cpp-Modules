#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form forma_a("Form01", 1, 1);
        std::cout << forma_a;
        Bureaucrat bureaucrat_a("Buru01", 0);
        std::cout << bureaucrat_a;
        bureaucrat_a.signForm(forma_a);
        std::cout << forma_a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
