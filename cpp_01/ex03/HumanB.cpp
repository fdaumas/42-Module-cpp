#include "HumanB.hpp"
#include "Weapon.hpp"


HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = nullptr;
}

HumanB::~HumanB() {
}

void HumanB::attack() {
	if (_weapon != nullptr)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::set_weapon(Weapon weapon) {
	_weapon = &weapon;
}