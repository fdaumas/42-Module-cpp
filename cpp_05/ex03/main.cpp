#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	std::srand(std::time(nullptr));
	Intern someRandomIntern;
	Form* form;
	try {
		form = someRandomIntern.makeForm("Robotomy request", "michel");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		form = someRandomIntern.makeForm("Presidential pardon", "michel");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		form = someRandomIntern.makeForm("Shrubbery creation", "michel");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	try {
		form = someRandomIntern.makeForm("error", "michel");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}