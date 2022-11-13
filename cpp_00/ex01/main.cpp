#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void	str_toupper(std::string &str) {
	int index_str = 0;

	while (str[index_str]) {
		str[index_str] = toupper(str[index_str]);
		index_str++;
	}
}

int	main() {
	PhoneBook	phonebook;
	int			index = 0;
	std::string	prompt;

	while (1) {
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		std::cin >> prompt;
		str_toupper(prompt);
		if (prompt == "ADD" && prompt.length() == 3) {
			phonebook.add_contact(index);
			index++;
			if (index > 7)
				index = 0;
		}
		else if (prompt == "SEARCH" && prompt.length() == 6)
			phonebook.search_contact();
		else if (prompt == "EXIT" && prompt.length() == 4)
			return (0);
		std::cout << "-------------------" << std::endl;
	}
}