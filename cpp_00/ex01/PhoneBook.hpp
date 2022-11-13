#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook {
public :
	PhoneBook(void);
	~PhoneBook(void);
	void add_contact(int index);
	void put_line(int index);
	void put_first_name(int index);
	void put_last_name(int index);
	void put_nickname(int index);
	void put_all(int index);
	void search_contact();

private:
	Contact array_contact[8];
};

#endif
