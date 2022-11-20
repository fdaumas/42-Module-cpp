#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap *michel = new ClapTrap("michel");
	std::cout << "-----constructor scavtrap-------" << std::endl;
	ScavTrap pierre("pierre");
	std::cout << "-----constructor scavtrap-------" << std::endl;
	ScavTrap jeanPierre(pierre);
	std::cout << "-----constructor scavtrap-------" << std::endl;
	std::cout << std::endl;

	pierre.attack("michel");
	jeanPierre.attack("michel");
	michel->takeDamage(pierre.getAttackDamage());
	michel->attack("pierre");
	pierre.guardGate();
	pierre.guardGate();
	pierre.takeDamage(100);
	pierre.attack("michel");
	std::cout << std::endl;
	delete michel;
	std::cout << "-----destructor scavtrap-------" << std::endl;
}