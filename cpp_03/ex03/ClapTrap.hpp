#ifndef CLAPTRAP_H_
# define CLAPTRAP_H_

#include <iostream>

class ClapTrap {
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &claptrap);
	~ClapTrap();
	ClapTrap&operator = (const ClapTrap &clapTrap);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setHitpoint(int amount);
	void setEnergypoints(int amount);
	void setAttackDamage(int amount);

	std::string getName();
	int getHitPoint();
	int getEnergyPoints();
	int getAttackDamage();

private:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
};

#endif