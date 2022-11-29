#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

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
	Form* form = new ShrubberyCreationForm("michel");
	test->signForm(*form);
	std::cout << *form << std::endl;
	test->executeForm(*form);
	delete test;
	delete form;
	return (0);
}