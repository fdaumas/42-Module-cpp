#include "ClapTrap.hpp"

int main() {
	ClapTrap roger("roger");
	ClapTrap michel("michel");

	roger.attack("michel");
	michel.takeDamage(0);
	roger.takeDamage(1);
	ClapTrap jeanpierre(roger);
	jeanpierre.takeDamage(10);
	jeanpierre.attack("michel");
}