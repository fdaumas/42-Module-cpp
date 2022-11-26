#include "Bureaucrat.hpp"

int main(int ac, char* av[]) {
	if (ac != 2) {
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
	std::cout << "after initialisation : " << *test << std::endl;
	test->incrementGrade();
	std::cout << "after increment : " << *test << std::endl;
	test->decrementGrade();
	std::cout << "after decrement : " << *test << std::endl;
	test->decrementGrade();
	std::cout << "after decrement : " << *test << std::endl;
	delete test;
	return (0);
}