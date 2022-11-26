#include "Form.hpp"

Form::Form(const std::string name, const int gradesigned, const int gradeexecute)
: _name(name), _signed(false), _gradeSigned(gradesigned), _gradeExecute(gradeexecute)
			{
	verifConstructor();
}

Form::Form(const Form &form) : _name(form._name), _gradeSigned(form._gradeSigned)
, _gradeExecute(form._gradeExecute) {
	*this = form;
}

Form::~Form() {}

Form& Form::operator = (const Form &form) {
	if (this == &form)
		return (*this);
	this->_signed = form._signed;
	return (*this);
}

bool Form::getSigned() const {
	return (_signed);
}

std::string Form::getName() const {
	return (_name);
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	try {
		verifCanSigned(bureaucrat);
	}
	catch (const std::exception& exception) {
		std::cerr << bureaucrat.getName() << " couldn't sign "
		<< this->getName() << " because " << exception.what() << std::endl;
		return ;
	}
	std::cout << bureaucrat.getName() << " signed " << this->getName()
	<< std::endl;
	_signed = true;
}

void Form::verifCanSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeSigned)
		throw (Form::GradeTooLowException());
}

void Form::verifConstructor() {
	if (this->_gradeSigned > 150 || this->_gradeExecute > 150)
		throw (Form::GradeTooLowException());
	if (this->_gradeSigned < 1 || this->_gradeExecute < 1)
		throw (Form::GradeTooHighException());
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream& operator << (std::ostream& out, Form const& form) {
	if (form.getSigned() == true) {
		out << form.getName() << " is signed";
	}
	else
		out << form.getName() << " is not signed";
	return (out);
}