#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
}

Zombie::~Zombie() {
	std::cout << "Destructor of " << this->_name << " called." << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}