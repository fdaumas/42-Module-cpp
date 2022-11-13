#ifndef WEAPON_H_
# define WEAPON_H_

#include <iostream>

class Weapon {
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon(void);

	std::string getType(void);
	void setType(std::string type);
};

#endif