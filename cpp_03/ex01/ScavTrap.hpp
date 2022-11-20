#ifndef SCAVTRAP_H_
# define SCAVTRAP_H_

#include "ClapTrap.hpp"

class ScavTrap:public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap();
	ScavTrap&operator = (const ScavTrap &scavtrap);

	void attack(const std::string& target);
	void guardGate();

private:
	bool _guardGate;
};

#endif