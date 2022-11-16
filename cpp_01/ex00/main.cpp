#include "Zombie.hpp"

int main(void) {
	Zombie* newzombie = newZombie("newZombie");
	randomChump("randomChump");
	newzombie->announce();
	delete newzombie;
	return (0);
}