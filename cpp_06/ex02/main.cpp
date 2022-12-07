
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	std::srand(std::time(nullptr));

	Base* test = generate();

	identify(test);
	identify(*test);
}