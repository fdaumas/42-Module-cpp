#include "easyfind.hpp"

const char * ::OutOfRange::what() const throw() {
	return ("Out of range");
}

int main() {
	std::vector<int> vector_test(1, 42);
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(42);
	lst.push_back(9);
	lst.push_back(68);
	lst.push_back(10);

	try {
		std::cout << (*easyfind(vector_test, 42)) << std::endl;
		std::cout << (*easyfind(lst, 68)) << std::endl;
		std::cout << (std::distance(lst.begin(), easyfind(lst, 68)))
				  << std::endl;
		std::cout	<< (*easyfind(lst, 10)) << std::endl;
		std::cout	<< (*easyfind(lst, 999)) << std::endl;
	} catch (std::exception &exception) {
		std::cerr << exception.what() << std::endl;
	}
	return (0);
}