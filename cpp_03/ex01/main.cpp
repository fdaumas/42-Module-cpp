#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap *michel = new ClapTrap("michel");
	std::cout << "-----constructor scavtrap-------" << std::endl;
	ScavTrap pierre("pierre");
	std::cout << std::endl;

	pierre.attack("michel");
	michel->takeDamage(pierre.getAttackDamage());
	michel->attack("pierre");
	pierre.guardGate();
	pierre.guardGate();
	pierre.takeDamage(100);
	michel->takeDamage(pierre.getAttackDamage());
	std::cout << std::endl;
	delete michel;
	std::cout << "-----destructor scavtrap-------" << std::endl;
}