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
}

void Contact::set_first_name() {
	std::cout << "first name   : ";
	std::cin >> this->_first_name;
}

void Contact::set_last_name() {
	std::cout << "last name    : ";
	std::cin >> this->_last_name;
}

void Contact::set_nickname() {
	std::cout << "nickname     : ";
	std::cin >> this->_nickname;
}

void Contact::set_phone_number() {
	std::cout << "phone number : ";
	std::cin >> this->_phone_number;
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
