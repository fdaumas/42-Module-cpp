#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(int ac, char* av[]) {
	if (ac != 2) {
		std::cerr << "bad number argument" << std::endl;
		return (1);
	}
	std::srand(std::time(nullptr));
	Bureaucrat* test;
	std::cout << "----TRY----" << std::endl;
	try {
		test = new Bureaucrat("michel", std::atoi(av[1]));
	}
	catch (const std::exception &exception) {
		std::cerr << exception.what() << std::endl;
		return (2);
	}
	std::cout << *test << std::endl;
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
		form = someRandomIntern.makeForm("Presidential Pardon", "michel");
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
	delete test;
	return (0);
}