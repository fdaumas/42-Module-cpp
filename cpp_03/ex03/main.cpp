#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap brother("bro");

	std::cout << std::endl;
	brother.attack("dude");
	brother.whoAmI();
	std::cout << std::endl;
	DiamondTrap super(brother);
	std::cout << std::endl;
	super.attack("dude n2");
	super.whoAmI();
	std::cout << std::endl;
	return (0);
}