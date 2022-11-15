#include "Zombie.hpp"

int main(void) {
	int n_zombie = 42;
	Zombie *zombiehorde = zombieHorde(n_zombie, "ZOMBIE");

	int index = 0;
	while (index < n_zombie) {
		std::cout << index << " ";
		zombiehorde[index++].announce();
	}

	delete [] zombiehorde;
	return (0);
}