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
	std::cout << "shortest span = " << random_span.shortestSpan()
			<< " ; longest span = " << random_span.longestSpan() << std::endl;
	std::cout << std::endl;
//############################################################################//
	std::cout << "###test addRandomNumberRange###" << std::endl;
	Span bigest_span = Span(10000);
	bigest_span.addRandomNumberRange(0, 9999);
	std::cout << "shortest span = " << bigest_span.shortestSpan()
			<< " ; longest span = " << bigest_span.longestSpan() << std::endl;
//############################################################################//
	std::cout << "###test exception###" << std::endl;
	Span small_span = Span(50);
	try {
		small_span.longestSpan();
	} catch (std::exception &exception) {
		std::cerr << exception.what() <<  std::endl;
	}
	try {
		small_span.shortestSpan();
	} catch (std::exception &exception) {
		std::cerr << exception.what() <<  std::endl;
	}
	small_span.addNumber(5);
	try {
		small_span.shortestSpan();
	} catch (std::exception &exception) {
		std::cerr << exception.what() <<  std::endl;
	}
	try {
		small_span.longestSpan();
	} catch (std::exception &exception) {
		std::cerr << exception.what() <<  std::endl;
	}
	small_span.addNumber(5);
	try {
		std::cout << small_span.shortestSpan() << " - "
			<< small_span.longestSpan();
	} catch (std::exception &exception) {
		std::cerr << exception.what() <<  std::endl;
	}
}