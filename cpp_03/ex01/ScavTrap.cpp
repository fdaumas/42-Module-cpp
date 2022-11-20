#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "string constructor of ScavTrap called" << std::endl;
	this->setHitpoint(100);
	this->setEnergypoints(50);
	this->setAttackDamage(20);
	_guardGate = false;
}

ScavTrap::~ScavTrap() {
	std::cout << "destructor of ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->getHitPoint() <= 0)
		return;
	std::cout << "ScavTrap " << this->getName() << " attacks " << target
			  << ", causing " << this->getAttackDamage() << " point of damage" << std::endl;
	this->setEnergypoints(this->getEnergyPoints() - 1);
}

void ScavTrap::guardGate() {
	if (_guardGate) {
		std::cout << "now guard gate is disable" << std::endl;
		_guardGate = false;
	}
	else if (!_guardGate) {
		std::cout << "now guard gate is enable" << std::endl;
		_guardGate = true;
	}
}