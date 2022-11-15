#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug() {
	std::cout <<
			  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
			  << std::endl;
}

void Harl::info() {
	std::cout <<
			  "I cannot believe adding extra bacon costs more money. You didn’t "
			  << "put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning() {
	std::cout <<
			  "I think I deserve to have some extra bacon for free. I’ve been "
			  << "coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error() {
	std::cout <<
			  "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void Harl::complain(std::string level) {
	my_map map;
	map.insert(std::make_pair("debug", &Harl::debug));
	map.insert(std::make_pair("info", &Harl::info));
	map.insert(std::make_pair("warning", &Harl::warning));
	map.insert(std::make_pair("error", &Harl::error));

	my_map::iterator it = map.find(level);
	if (it != map.end())
		(this->*(it->second))();
}
