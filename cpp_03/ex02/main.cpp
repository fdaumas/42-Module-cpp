#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "-----constructor scavtrap-------" << std::endl;
	ScavTrap pierre("pierre");
	std::cout << "-----constructor copy scavtrap-------" << std::endl;
	ScavTrap jeanPierre(pierre);
	std::cout << "-----constructor fragtrap-------" << std::endl;
	FragTrap macron("macron");
	std::cout << "-----constructor copy fragtrap-------" << std::endl;
	FragTrap brigitte(macron);
	std::cout << "-----main-------" << std::endl;
	std::cout << std::endl;

	pierre.attack("michel");
	jeanPierre.attack("michel");
	pierre.guardGate();
	pierre.guardGate();
	pierre.takeDamage(100);
	pierre.attack("michel");
	std::cout << std::endl;

	macron.attack("pierre");
	brigitte.attack("pierre");
	macron.highFiveGuys();
	macron.takeDamage(100);
	macron.attack("pierre");
	std::cout << "-----destructor-------" << std::endl;
}