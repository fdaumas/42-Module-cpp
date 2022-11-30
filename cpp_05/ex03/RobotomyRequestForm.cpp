#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& string) :
		Form("Robotomy request form", 72, 45), _target(string)
{}

RobotomyRequestForm::RobotomyRequestForm
		(const RobotomyRequestForm &robotomy) :
		Form(robotomy.getName(), robotomy.getGradeRequiredSign(),
			 robotomy.getGradeRequiredExecute()), _target(robotomy._target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator =
		(const RobotomyRequestForm& robotomy) {
	if (this == &robotomy)
		return (*this);
	this->_target = robotomy._target;
	this->setsigned(robotomy.getSigned());
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw (Form::FormNotSigned());
	if (!this->verifCanExecute(executor))
		throw (Form::GradeTooLowException());
	std::cout << "*DRILL NOISES*" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "Target " << this->_target
		<< " has been succesfully robotomized !" << std::endl;
	else
		std::cout << "Target " << this->_target
		<< " couldn't be robotomized..." << std::endl;
}
