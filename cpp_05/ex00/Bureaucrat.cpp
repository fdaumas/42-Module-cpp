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

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this == &bureaucrat)
		return (*this);
	this->_name = bureaucrat.getName();
	this->_grade = bureaucrat.getGrade();
	return (*this);
}

void Bureaucrat::verifGrade() {
	if (this->_grade < 1) {
		throw ("Grade cannot exceed 1");
	}
	if (this->_grade > 150) {
		throw ("Grade cannot be below 150");
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
	verifGrade();
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	verifGrade();
}

std::ostream& operator << (std::ostream& out, const Bureaucrat bureaucrat) {
	out << "Name  : " << bureaucrat.getName() << std::endl
		<< "Grade : " << bureaucrat.getGrade();
	return (out);
}
