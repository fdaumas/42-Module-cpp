#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "Default constructor called" << std::endl;
	_attackDamage = 0;
	_energyPoints = 10;
	_hitPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap::~ClapTrap() {
	std::cout << "destructor of ClapTrap" << std::endl;
}

/* Copy Operator */
ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap) {
	std::cout << "Copy assignememt operator called" << std::endl;
	if (this == &clapTrap)
		return (*this);
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	return (*this);
}

/* Member function */
void ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	<< ", causing " << this->_attackDamage << " point of damage" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage"
		<< std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " repaired from " << amount
		<< std::endl;
	this->_energyPoints--;
}