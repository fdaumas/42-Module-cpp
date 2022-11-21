#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name) {
	std::cout << "string constructor of ClapTrap called" << std::endl;
	_attackDamage = 0;
	_energyPoints = 10;
	_hitPoints = 10;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	std::cout << "Copy constructor called of ClapTrap" << std::endl;
	*this = claptrap;
}

ClapTrap::~ClapTrap() {
	std::cout << "destructor of ClapTrap" << std::endl;
}

/* Copy Operator */
ClapTrap &ClapTrap::operator = (const ClapTrap &clapTrap) {
	std::cout << "Copy assignememt operator of ClapTrap called" << std::endl;
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

void ClapTrap::setHitpoint(int amount) {
	this->_hitPoints = amount;
}

void ClapTrap::setAttackDamage(int amount) {
	this->_attackDamage = amount;
}

void ClapTrap::setEnergypoints(int amount) {
	this->_energyPoints = amount;
}

int ClapTrap::getHitPoint() {
	return this->_hitPoints;
}

int ClapTrap::getAttackDamage() {
	return this->_attackDamage;
}

int ClapTrap::getEnergyPoints() {
	return this->_energyPoints;
}

std::string ClapTrap::getName() {
	return this->_name;
}
