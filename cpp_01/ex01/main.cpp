#include "Zombie.hpp"

int main(void) {
	Zombie* zombiehorde = zombieHorde(42, "Zombie");
	delete [] zombiehorde;
	return (0);
}