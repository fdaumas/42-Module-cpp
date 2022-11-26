#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(int ac, char* av[]) {
	if (ac != 3) {
		std::cerr << "bad number argument" << std::endl;
		return (1);
	}
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
	Form* form;
	try {
		form = new Form("SUPER", std::atoi(av[2]), 100);
	}
	catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
		delete test;
		return (3);
	}
	test->signForm(*form);
	std::cout << *form << std::endl;
	delete test;
	delete form;
	return (0);
}