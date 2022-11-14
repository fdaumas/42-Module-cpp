#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add_contact(int index) {
	this->_array_contact[index].set_all();
}

void PhoneBook::put_line(int index) {
	std::cout << "|" << std::right << std::setw(10) << index << std::setfill(' ');
	put_first_name(index);
	put_last_name(index);
	put_nickname(index);
	std::cout << "|" << std::endl;
}

void PhoneBook::put_first_name(int index) {
	if (this->_array_contact[index].get_first_name().length() > 10) {
		int index_str = 0;
		std::cout << "|";
		while (index_str < 9)
			std::cout << this->_array_contact[index].get_first_name()[index_str++];
		std::cout << ".";
	}
	else
		std::cout << "|" << std::right << std::setw(10) << this->_array_contact[index].get_first_name() << std::setfill(' ');
}

void PhoneBook::put_last_name(int index) {
	if (this->_array_contact[index].get_last_name().length() > 10) {
		int index_str = 0;
		std::cout << "|";
		while (index_str < 9)
			std::cout << this->_array_contact[index].get_last_name()[index_str++];
		std::cout << ".";
	}
	else
		std::cout << "|" << std::right << std::setw(10) << this->_array_contact[index].get_last_name() << std::setfill(' ');
}

void PhoneBook::put_nickname(int index) {
	if (this->_array_contact[index].get_nickname().length() > 10) {
		int index_str = 0;
		std::cout << "|";
		while (index_str < 9)
			std::cout << this->_array_contact[index].get_nickname()[index_str++];
		std::cout << ".";
	}
	else
		std::cout << "|" << std::right << std::setw(10) << this->_array_contact[index].get_nickname() << std::setfill(' ');
}

void PhoneBook::put_all(int index) {
	std::cout << "first name     : " << this->_array_contact[index].get_first_name()
	<< std::endl;
	std::cout << "last name      : " << this->_array_contact[index].get_last_name()
	<< std::endl;
	std::cout << "nickname       : " << this->_array_contact[index].get_nickname()
	<< std::endl;
	std::cout << "phone number   : " << this->_array_contact[index].get_phone_number()
	<< std::endl;
	std::cout << "darkest secret : " << this->_array_contact[index].get_darkest_secret()
	<< std::endl;
}

void PhoneBook::search_contact() {
	int index = 0;
	std::string answer;

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	while (index < 8) {
		this->put_line(index);
		index++;
	}
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "enter the index of your choice : ";
	if (!std::getline(std::cin, answer))
		return ;
	if ((answer == "EXIT" || answer == "exit") && answer.length() == 4)
		exit(0);
	if (answer.length() != 1 || answer < "0" || answer > "7") {
		std::cout << "Bad index" << std::endl;
		return ;
	}
	else
		this->put_all(answer[0] - '0');
}
