#ifndef _PRESIDENTIALPARDONFORM_H_
# define _PRESIDENTIALPARDONFORM_H_

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(const std::string& string);
		PresidentialPardonForm(const PresidentialPardonForm& presidential);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator =
				(const PresidentialPardonForm& presidential);
		void execute(Bureaucrat const &executor) const;
	private:
		std::string _target;
};

#endif