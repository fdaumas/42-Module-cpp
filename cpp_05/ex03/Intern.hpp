#ifndef _INTERN_H_
# define _INTERN_H_

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();
		Intern& operator = (const Intern& intern);
		Form* createForm(const std::string& name, const std::string& target);
		Form* makeForm(const std::string& name, const std::string& target);
		class InterCannotCreateForm : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

#endif