#include "Span.hpp"

int main() {
	std::srand(std::time(nullptr));
//############################################################################//
	std::cout << "###constructor default test###" << std::endl;
	try {
		Span default_span = Span();
	} catch (std::exception & exception) {
		std::cerr << exception.what() << std::endl;
	}
	std::cout << std::endl;
//############################################################################//
	std::cout << "###Crash needed and print all_vector###" << std::endl;
	Span span = Span(3);
	span.addNumber(5);
	span.addNumber(12);
	span.addNumber(42);
	try {
		span.addNumber(420);
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}
	span.test_3_nb();
	std::cout << std::endl;
//############################################################################//
	std::cout << "###test addRandomNumberRange###" << std::endl;
	Span random_span = Span(10);
	random_span.addNumber(42);
	random_span.addRandomNumberRange(0, 9);
	random_span.test();
	std::cout << std::endl;
//############################################################################//
}