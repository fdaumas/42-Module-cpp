#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon() {
}

std::string Weapon::getType(void){
	return (_type);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}
