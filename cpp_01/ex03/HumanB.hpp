#ifndef HUMANB_H_
# define HUMANB_H_

#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon weapon;

public:
	HumanB(std::string name, Weapon &weapon);
	~HumanB(void);
	void attack();
};

#endif
