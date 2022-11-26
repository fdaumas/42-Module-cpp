#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :
_name(name), _grade(grade) {
	verifGrade();
}

Bureaucrat::Bureaucrat(std::string name) :
_name(name), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) {
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this == &bureaucrat)
		return (*this);
	this->_name = bureaucrat.getName();
	this->_grade = bureaucrat.getGrade();
	return (*this);
}

void Bureaucrat::verifGrade() {
	if (this->_grade < 1) {
		throw (Bureaucrat::GradeTooHighException());
	}
	if (this->_grade > 150) {
		throw (Bureaucrat::GradeTooLowException());
	}
}

std::string Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	this->_grade--;
	try {
		verifGrade();
	}
	catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
		this->_grade++;
	}
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	try {
		verifGrade();
	}
	catch (const std::exception& exception) {
		std::cerr << exception.what() << std::endl;
	this->_grade--;
	}
}

std::ostream& operator << (std::ostream& out, const Bureaucrat bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " <<
	bureaucrat.getGrade() << ".";
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade cannot exceed 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade cannot be below 150");
}
