#include "Harl.hpp"

int main () {
	Harl harl;

	std::cout << "DEBUG : " << std::endl;
	harl.complain("debug");
	std::cout << "------------" << std::endl;
	std::cout << "INFO : " << std::endl;
	harl.complain("info");
	std::cout << "------------" << std::endl;
	std::cout << "WARNING : " << std::endl;
	harl.complain("warning");
	std::cout << "------------" << std::endl;
	std::cout << "ERROR : " << std::endl;
	harl.complain("error");
}