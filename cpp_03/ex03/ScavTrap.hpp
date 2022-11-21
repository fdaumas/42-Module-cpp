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

	void setHitPointScavTrap(int amount);
	void setEnergypointsScavTrap(int amount);
	void setAttackDamageScavTrap(int amount);
private:
	bool _guardGate;
};

#endif