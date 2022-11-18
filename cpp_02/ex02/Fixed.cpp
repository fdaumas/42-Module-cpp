#include "Fixed.hpp"

/* Constructor default int float, destucteur
 * I delete ALL message (default constructor called, int constructor called,
 * ...) for better lisibility*/
Fixed::Fixed() {
	this->_number = 0;
}

Fixed::Fixed(int int_number) {
	this->_number = int_number << this->_number_fractional_bits;
}

Fixed::Fixed(float float_number) {
	this->_number = (float_number * (1 << this->_number_fractional_bits));
}
/**
 * COPY CONSTRUCTOR
 * copy constructor can use operator= like the actual code
 * or like the comment line 15 (for that comment line 14)
 * @param &fixed
 */
Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
	//	this->_number = fixed.getRawBits();
}

Fixed::~Fixed() {
}

/* getter */
int Fixed::getRawBits() const {
	return (_number);
}

/* setter */
void Fixed::setRawBits(const int raw) {
	this->_number = raw;
}

/* Convertion function */
int Fixed::toInt() const {
	return (this->_number / (1 << this->_number_fractional_bits));
}

float Fixed::toFloat() const {
	return ((float)this->_number / (float)(1 << this->_number_fractional_bits));
}

/* min max */
Fixed& Fixed::max(Fixed &f1, Fixed &f2) {
	return (f1 >= f2 ? (f1) : (f2));
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2) {
	return (f1 >= f2 ? (f1) : (f2));
}

Fixed& Fixed::min(Fixed &f1, Fixed &f2) {
	return (f1 <= f2 ? (f1) : (f2));
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2) {
	return (f1 <= f2 ? (f1) : (f2));
}

/* Copy Operator */
Fixed &Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed)
		return (*this);
	this->_number = fixed.getRawBits();
	return (*this);
}

/* Comparaisons Operator */
bool Fixed::operator > (const Fixed &other) const {return (toFloat() > other.toFloat());}
bool Fixed::operator < (const Fixed &other) const {return (toFloat() < other.toFloat());}
bool Fixed::operator <= (const Fixed &other) const {return (toFloat() <= other.toFloat());}
bool Fixed::operator >= (const Fixed &other) const {return (toFloat() >= other.toFloat());}
bool Fixed::operator == (const Fixed &other) const {return (toFloat() == other.toFloat());}
bool Fixed::operator != (const Fixed &other) const {return (toFloat() != other.toFloat());}

/* Arithmetics Operator */
float Fixed::operator + (const Fixed &other) {return (toFloat() + other.toFloat());}
float Fixed::operator - (const Fixed &other) {return (toFloat() - other.toFloat());}
float Fixed::operator * (const Fixed &other) {return (toFloat() * other.toFloat());}
float Fixed::operator / (const Fixed &other) {return (toFloat() / other.toFloat());}

/* pre|post increment|decrement Operator */
Fixed Fixed::operator ++ () {
	this->_number++;
	return (*this);
}

Fixed Fixed::operator ++ (int) {
	const Fixed tmp(*this);
	this->_number++;
	return (tmp);
}

Fixed Fixed::operator -- () {
	this->_number--;
	return (*this);
}

Fixed Fixed::operator -- (int) {
	const Fixed tmp(*this);
	this->_number--;
	return (tmp);
}

/* Operator for Fixed in std::cout */
std::ostream& operator << (std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
/* Operator for boolean verif WARNING this is weird but just for my presentation
 * and my knowledge */
std::ostream& operator < (std::ostream& out, const bool boolean) {
	return (boolean ? (out << "true") : (out << "false"));
}