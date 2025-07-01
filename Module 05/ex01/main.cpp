#include "Bureaucrat.hpp"
#include "Form.hpp"


int main() {
	try {
		Bureaucrat bureaucratA("bureaucratA", 50);
		Bureaucrat bureaucratB("bureaucratB", 1);

		Form formX("Form_X", 45, 30);
		Form formY("Form_Y", 1, 1);
		Form formZ("Form_Z", 100, 80);

		std::cout << "-- forms before signing --\n";
		std::cout << formX;
		std::cout << formY;
		std::cout << formZ;

		std::cout << "-- bureaucratA signing formZ (grade 50 > 100) --\n";
		bureaucratA.signForm(formZ);

		std::cout << "-- bureaucratB signing formY (grade 1 == 1) --\n";
		bureaucratB.signForm(formY);

		std::cout << "\n-- bureaucratA signing formX (grade 50 < 45) -- fails --\n";
		bureaucratA.signForm(formX);

		std::cout << "-- forms after signing --\n";
		std::cout << formX;
		std::cout << formY;
		std::cout << formZ;
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
