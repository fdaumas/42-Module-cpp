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
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}