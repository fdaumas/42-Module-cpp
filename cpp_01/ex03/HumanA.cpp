#include "HumanA.hpp"
#include "Weapon.hpp"


HumanA::HumanA(std::string name, Weapon &weapon) {
	this->_name = name;
	this->_weapon = &weapon;
}

HumanA::~HumanA() {
}

void HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}