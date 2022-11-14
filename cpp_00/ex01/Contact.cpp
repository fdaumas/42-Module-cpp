#include "PhoneBook.hpp"
#include <iostream>

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::set_all() {
	this->set_first_name();
	this->set_last_name();
	this->set_nickname();
	this->set_phone_number();
	this->set_darkest_secret();
}

void Contact::set_first_name() {
	std::cout << "first name     : ";
	if (!std::getline(std::cin, this->_first_name))
		exit(0);
	while (_first_name.length() == 0) {
		std::cout << "first name     : ";
		if (!std::getline(std::cin, this->_first_name))
			exit(0);
	}
}

void Contact::set_last_name() {
	std::cout << "last name      : ";
	if (!std::getline(std::cin, this->_last_name))
		exit(0);
	while (_last_name.length() == 0) {
		std::cout << "last name      : ";
		if (!std::getline(std::cin, this->_last_name))
			exit(0);
	}
}

void Contact::set_nickname() {
	std::cout << "nickname       : ";
	if (!std::getline(std::cin, this->_nickname))
		exit(0);
	while (_nickname.length() == 0) {
		std::cout << "nickname       : ";
		if (!std::getline(std::cin, this->_nickname))
			exit(0);
	}
}

void Contact::set_phone_number() {
	std::cout << "phone number   : ";
	if (!std::getline(std::cin, this->_phone_number))
		exit(0);
	while (_phone_number.length() == 0) {
		std::cout << "phone number   : ";
		if (!std::getline(std::cin, this->_phone_number))
			exit(0);
	}
}

void Contact::set_darkest_secret() {
	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, this->_darkest_secret))
		exit(0);
	while (_darkest_secret.length() == 0) {
		std::cout << "darkest secret : ";
		if (!std::getline(std::cin, this->_darkest_secret))
			exit(0);
	}
}

std::string Contact::get_first_name() {
	return this->_first_name;
}

std::string Contact::get_last_name() {
	return this->_last_name;
}

std::string Contact::get_nickname() {
	return this->_nickname;
}

std::string Contact::get_phone_number() {
	return this->_phone_number;
}

std::string Contact::get_darkest_secret() {
	return this->_darkest_secret;
}
