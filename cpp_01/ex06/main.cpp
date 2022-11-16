#include "Harl.hpp"

std::string 	str_toupper(std::string str) {
	int index_str = 0;

	while (str[index_str]) {
		str[index_str] = toupper(str[index_str]);
		index_str++;
	}
	return (str);
}

int main (int ac, char *av[]) {
	Harl harl;

	if (ac != 2) {
		std::cout << "bad number of argument" << std::endl;
		return (1);
	}
	harl.complain(str_toupper(av[1]));
	return (0);
}