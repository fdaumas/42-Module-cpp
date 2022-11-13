#ifndef ZOMBIE_H_
# define ZOMBIE_H_

# include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif