#include "Bureaucrat.hpp"

int main() {
	Bureaucrat* test;
	std::cout << "----TRY----" << std::endl;
	try {
		test = new Bureaucrat("michel", 100);
		std::cout << *test << std::endl;
		delete test;
	}
	catch (const char* exception) {
		std::cout << exception << std::endl;
		return (0);
	}
	std::cout << "----TRY----" << std::endl;
	test = new Bureaucrat("michel");
	std::cout << *test << std::endl;
	try {
		test->decrementGrade();
	}
	catch (const char* exception) {
		std::cout << exception << std::endl;
		test->incrementGrade();
	}
	std::cout << *test << std::endl;
	delete test;
	std::cout << "----TRY----" << std::endl;
	test = new Bureaucrat("michel", 1);
	std::cout << *test << std::endl;
	try {
		test->incrementGrade();
	}
	catch (const char* exception) {
		std::cout << exception << std::endl;
		test->decrementGrade();
	}
	std::cout << *test << std::endl;
	std::cout << "----TRY----" << std::endl;
	delete test;
	return (0);
}