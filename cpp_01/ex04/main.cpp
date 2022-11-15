#include <iostream>
#include "replaceFile.hpp"

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Bad number of argument" << std::endl;
		return (1);
	}
	int len_s1 = std::char_traits<char>::length(argv[2]);

	if (len_s1 <= 0) {
		std::cout << "error s1" << std::endl;
		return (2);
	}
	replaceFile file(argv[1], argv[2], argv[3]);
	file.old_to_new(len_s1);
	file.new_to_file(argv[1]);
	return (0);
}