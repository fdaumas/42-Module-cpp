#include "Literal.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Bad argument" << std::endl;
		return (1);
	}
	Literal* literal;
	try {
		literal = new Literal(argv[1]);
	}
	catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
		return (1);
	}
	literal->print();
	delete literal;
	return (0);
}