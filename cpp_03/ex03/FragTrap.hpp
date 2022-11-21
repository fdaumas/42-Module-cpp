#ifndef FRAGTRAP_H_
# define FRAGTRAP_H_

#include "ClapTrap.hpp"

class FragTrap:public ClapTrap {
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &scavTrap);
	~FragTrap();
	FragTrap&operator = (const FragTrap &fragtrap);

	void attack(const std::string& target);
	void highFiveGuys();

	void setHitPointFragTrap(int amount);
	void setEnergypointsFragTrap(int amount);
	void setAttackDamageFragTrap(int amount);
};

#endif
