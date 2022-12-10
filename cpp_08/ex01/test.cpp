#include "Span.hpp"

int main() {
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	std::cout << "0. size: " << v.size() << std::endl;

	v.insert(v.end(), 10, 100);
	std::cout << "1. size: " << v.size() << std::endl;
	std::cout << (*std::find(v.begin(), v.end(), 100)) << std::endl;
}