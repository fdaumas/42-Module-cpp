#ifndef ZOMBIE_H_
# define ZOMBIE_H_

# include <iostream>

class Zombie {
private:
	std::string _name;

public:
	Zombie(void);
	~Zombie(void);

	void announce(void);
	void set_name(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
