#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::put_line(int index) {
	std::cout << "|         " << index << "|";
	this->put_first_name(index);
	std::cout << '|';
	this->put_last_name(index);
	std::cout << '|';
	this->put_nickname(index);
	std::cout << '|' << std::endl;
}

void PhoneBook::add_contact(int index) {
	this->array_contact[index].set_all();
}

void PhoneBook::put_first_name(int index) {
	std::string new_first_name;
	int index_str = 0;

	if (this->array_contact[index].get_first_name().length() >= 10) {
		new_first_name = this->array_contact[index].get_first_name();
		new_first_name[9] = '.';
		while (index_str < 10)
			std::cout << new_first_name[index_str++];
	}
	else {
		new_first_name = this->array_contact[index].get_first_name();
		while (new_first_name.length() + index_str++ < 10)
			std::cout << ' ';
		std::cout << new_first_name ;
	}
}

void PhoneBook::put_last_name(int index) {
	std::string new_last_name;
	int index_str = 0;

	if (this->array_contact[index].get_last_name().length() >= 10) {
		new_last_name = this->array_contact[index].get_last_name();
		new_last_name[9] = '.';
		while (index_str < 10)
			std::cout << new_last_name[index_str++];
	}
	else {
		new_last_name = this->array_contact[index].get_last_name();
		while (new_last_name.length() + index_str++ < 10)
			std::cout << ' ';
		std::cout << new_last_name ;
	}
}

void PhoneBook::put_nickname(int index) {
	std::string new_nickname;
	int index_str = 0;

	if (this->array_contact[index].get_nickname().length() >= 10) {
		new_nickname = this->array_contact[index].get_nickname();
		new_nickname[9] = '.';
		while (index_str < 10)
			std::cout << new_nickname[index_str++];
	}
	else {
		new_nickname = this->array_contact[index].get_nickname();
		while (new_nickname.length() + index_str++ < 10)
			std::cout << ' ';
		std::cout << new_nickname ;
	}
}

void PhoneBook::put_all(int index) {
	std::cout << "first name   : " << this->array_contact[index].get_first_name()
	<< std::endl;
	std::cout << "last name    : " << this->array_contact[index].get_last_name()
	<< std::endl;
	std::cout << "nickname     : " << this->array_contact[index].get_nickname()
	<< std::endl;
	std::cout << "phone number : " << this->array_contact[index].get_nickname()
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
	std::cin >> answer;
	if ((answer == "EXIT" || answer == "exit") && answer.length() == 4)
		exit(0);
	if (answer.length() != 1 || answer < "0" || answer > "7") {
		std::cout << "Bad index" << std::endl;
		return ;
	}
	else
		this->put_all(answer[0] - '0');
}
