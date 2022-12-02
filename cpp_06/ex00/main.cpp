#include "Litteral.hpp"

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Bad argument" << std::endl;
		return (1);
	}
	Litteral* litteral;
	try {
		litteral = new Litteral(argv[1]);
	}
	catch (std::exception& exception) {
		std::cerr << exception.what() << std::endl;
		return (1);
	}
	litteral->print();
	delete litteral;
	return (0);
}