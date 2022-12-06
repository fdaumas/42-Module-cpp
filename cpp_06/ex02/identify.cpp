#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	switch (std::rand() % 3) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << "this is A identify with *" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "this is B identify with *" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "this is C identify with *" << std::endl;
}

void identify(Base& p) {
	if (dynamic_cast<A &>(p))
		std::cout << "this is A identify with &" << std::endl;
	if (dynamic_cast<B &>(p))
		std::cout << "this is B identify with &" << std::endl;
	if (dynamic_cast<C &>(p))
		std::cout << "this is C identify with &" << std::endl;
}
