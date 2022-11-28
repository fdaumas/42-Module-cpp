#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& string) :
Form("Presidential pardon form", 25, 5), _target(string)
{}

PresidentialPardonForm::PresidentialPardonForm
(const PresidentialPardonForm &presidential) :
	Form(presidential.getName(), presidential.getGradeRequiredSign(),
		 presidential.getGradeRequiredExecute()), _target(presidential._target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator =
		(const PresidentialPardonForm& presidential) {
	if (this == &presidential)
		return (*this);
	this->_target = presidential._target;
	this->setsigned(presidential.getSigned());
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw (Form::FormNotSigned());
	if (!this->verifCanExecute(executor))
		throw (Form::GradeTooLowException());
	std::cout << "target " << this->_target
	<< " has been forgiven by Zaphod Beeblerox" << std::endl;
}