#include "HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB() {
}

void HumanB::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::set_weapon(Weapon weapon) {
	_weapon = &weapon;
}