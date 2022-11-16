#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() {
	std::cout << "[DEBUG]" << std::endl <<
			  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
}

void Harl::info() {
	std::cout << "[INFO]" << std::endl <<
			  "I cannot believe adding extra bacon costs more money. You didn’t "
			  << "put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning() {
	std::cout << "[WARNING]" << std::endl <<
			  "I think I deserve to have some extra bacon for free. I’ve been "
			  << "coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error() {
	std::cout << "[ERROR]" << std::endl <<
			  "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void Harl::put_bad_level() {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level) {
	std::string enter[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int index = 0;

	while (enter[index] != level && index < 4)
		index++;
	switch (index) {
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break ;
		default:
			this->put_bad_level();
	}
}

