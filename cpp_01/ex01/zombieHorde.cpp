#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* zombiehorde = new Zombie[N];
	int index = 0;
	while (index < N) {
		zombiehorde[index].set_name(name);
		index++;
	}
	return (zombiehorde);
}