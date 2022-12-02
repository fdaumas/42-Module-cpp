#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &intern) {
	(void)intern;
	return (*this);
}

Form* Intern::makeForm(const std::string &name, const std::string &target) {
	std::string nameform[3] = {"Presidential pardon",
							   "Robotomy request",
							   "Shrubbery creation"};
	int index_form = 0;
	while (nameform[index_form] != name && index_form < 3)
		index_form++;
	Form* form;
	switch (index_form) {
		case 0:
			form = new PresidentialPardonForm(target);
			std::cout << "Intern create " << name << std::endl;
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			std::cout << "Intern create " << name << std::endl;
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			std::cout << "Intern create " << name << std::endl;
			break;
		default:
			throw (Intern::InterCannotCreateForm());
	}
	return (form);
}

const char* Intern::InterCannotCreateForm::what() const throw() {
	return ("This form does not have a template\nIntern cannot create that");
}