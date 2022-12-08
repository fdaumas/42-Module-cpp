#include "iter.hpp"

int main() {
	int int_arr[] = {0, 1, 2, 3, 4};
	iter(int_arr, 5, print);
	std::string string_arr[] = {"a", "b", "c"};
	iter(string_arr, 3, print);
	return (0);
}