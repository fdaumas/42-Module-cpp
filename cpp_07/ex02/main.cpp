#include "Array.hpp"

int main () {
	Array<int> * array = new Array<int>(50);
	Array<int> * array_cp = new Array<int>(10);

	std::cout << "size array cp : " << array_cp->size() << std::endl;
	*array_cp = *array;
	std::cout << "size array cp after : " << array_cp->size() << std::endl;
	try {
		std::cout << (*array_cp)[49] << std::endl;
	} catch (std::exception & exception) {
		std::cerr << exception.what() << std::endl;
	}
	delete array_cp;
	delete array;
	//########################################################################//
	Array<int> bob;
	try {
		bob[0] = 0;
	}
	catch (std::exception & exception) {
		std::cerr << exception.what() << std::endl;
	}
	//########################################################################//
	const Array<int> const_array(30);

	try {
		std::cout << (const_array)[29] << std::endl;
	}
	catch (std::exception & exception) {
		std::cerr << exception.what() << std::endl;
	}


}