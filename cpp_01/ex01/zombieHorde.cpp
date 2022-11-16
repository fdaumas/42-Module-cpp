#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0) {
		std::cout << "you can't have negative number of zombie" << std::endl;
		exit(1);
	}
	Zombie* zombiehorde = new Zombie[N];
	int index = 0;
	while (index < N) {
		zombiehorde[index].set_name(name);
		index++;
	}
	return (zombiehorde);
}