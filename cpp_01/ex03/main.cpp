
#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {

	Weapon club("club");
	HumanA humana("michel", club);
	humana.attack();
	club.setType("michelline");
	humana.attack();

	Weapon club2("AK 47");
	HumanB humanb("Roger");
	humanb.set_weapon(club2);
	humanb.attack();
	club2.setType("desert eagle");
	humanb.attack();
}