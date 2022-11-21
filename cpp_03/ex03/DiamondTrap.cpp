#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :
ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << "string constructor of DiamondTrap called" << std::endl;
	this->setHitPointFragTrap(100);
	this->setAttackDamageFragTrap(30);
	this->setEnergypointsScavTrap(50);
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) {
	std::cout << "Copy constructor of DiamondTrap called" << std::endl;
	*this = diamondtrap;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "destructor of DiamondTrap" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
	std::cout << "Copy assignememt operator of ClapTrap called"
	<< std::endl;
	if (this == &diamondTrap)
		return (*this);
	this->_name = diamondTrap._name;
	this->ClapTrap::_name = diamondTrap.ClapTrap::_name;
	this->_guardGate = diamondTrap._guardGate;
	this->setHitPointFragTrap(diamondTrap._hitPoints);
	this->setAttackDamageFragTrap(diamondTrap._attackDamage);
	this->setEnergypointsScavTrap(diamondTrap._energyPoints);
	return (*this);
}

void DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << _name << std::endl
	<< "My clap name is " << this->ClapTrap::_name
	<< std::endl;
}