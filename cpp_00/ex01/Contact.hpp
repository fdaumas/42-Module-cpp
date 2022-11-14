#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
public:
	Contact(void);
	~Contact(void);
	void set_first_name(void);
	void set_last_name(void);
	void set_nickname(void);
	void set_phone_number(void);
	void set_darkest_secret(void);
	void set_all(void);
	std::string get_first_name(void);
	std::string get_last_name(void);
	std::string get_nickname(void);
	std::string get_phone_number(void);
	std::string get_darkest_secret(void);

private :
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif