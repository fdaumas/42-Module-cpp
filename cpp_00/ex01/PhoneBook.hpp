#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class phonebook {
public :
	phonebook(void);
	~phonebook(void);
	void add_contact(void);

private:
	contact _tabs[8];
};

#ENDIF
