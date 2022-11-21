#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "string constructor of FragTrap called" << std::endl;
	this->setHitpoint(100);
	this->setEnergypoints(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap() {
	std::cout << "destructor of FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap) {
	std::cout << "Copy constructor of FragTrap called" << std::endl;
	*this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
	std::cout << "Copy assignememt operator of FragTrap called" << std::endl;
	if (this == &fragtrap)
		return (*this);
	ClapTrap::operator=(fragtrap);
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (this->getHitPoint() <= 0)
		return;
	std::cout << "FragTrap " << this->getName() << " attacks " << target
			  << ", causing " << this->getAttackDamage() << " point of damage" << std::endl;
	this->setEnergypoints(this->getEnergyPoints() - 1);
}

void FragTrap::highFiveGuys() {
	if (this->getHitPoint() > 0) {
		std::cout << "High Five bro" << std::endl;
	}
}

void FragTrap::setAttackDamageFragTrap(int amount) {
	this->setAttackDamage(amount);
}

void FragTrap::setHitPointFragTrap(int amount) {
	this->setHitpoint(amount);
}

void FragTrap::setEnergypointsFragTrap(int amount) {
	this->setEnergypoints(amount);
}
