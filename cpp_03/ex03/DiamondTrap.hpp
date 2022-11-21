#ifndef DIAMONDTRAP_H_
# define DIAMONDTRAP_H_

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondtrap);
	~DiamondTrap();
	DiamondTrap&operator = (const DiamondTrap &diamondTrap);

	void attack(const std::string &target);
	void whoAmI();

private:
	std::string _name;
};

#endif
