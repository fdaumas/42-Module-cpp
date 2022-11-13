#include <iostream>

int main(void) {
	std::string A = "HI THIS IS BRAIN";
	std::string *stringPTR = &A;
	std::string &stringREF = A;

	std::cout << "memory A : " << &A << std::endl;
	std::cout << "memory stringPTR : " << stringPTR << std::endl;
	std::cout << "memory stringREF : " << &stringREF << std::endl;

	std::cout << "value A : " << A << std::endl;
	std::cout << "value stringPTR : " << *stringPTR << std::endl;
	std::cout << "value stringREF : " << stringREF << std::endl;
	return (0);
}