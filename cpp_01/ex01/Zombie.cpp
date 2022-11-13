#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Constructor of zombieHorde" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Destructor of " << this->_name << " called." << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->_name = name;
}
