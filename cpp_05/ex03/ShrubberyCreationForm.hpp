#ifndef _SHRUBBERYCREATIONFORM_H
# define _SHRUBBERYCREATIONFORM_H

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm(const std::string& string);
		ShrubberyCreationForm(const ShrubberyCreationForm& shrubbery);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator =
				(const ShrubberyCreationForm& shrubbery);
		void execute(Bureaucrat const &executor) const;
	private:
		std::string _target;
};

#endif
