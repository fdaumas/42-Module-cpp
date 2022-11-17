#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_number = 0;
}

Fixed::Fixed(int int_number) {
	std::cout << "Int constructor called" << std::endl;
	this->_number = int_number << this->_number_fractional_bits;
}

Fixed::Fixed(float float_number) {
	std::cout << "Float constructor called" << std::endl;
	this->_number = (float_number * (1 << this->_number_fractional_bits));
}
/**
 * COPY CONSTRUCTOR
 * copy constructor can use operator= like the actual code
 * or like the comment line 15 (for that comment line 14)
 * @param &fixed
 */
Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	//	this->_number = fixed.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	if (this == &fixed)
		return (*this);
	std::cout << "Copy assignememt operator called" << std::endl;
	this->_number = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits function member called" << std::endl;
	return (_number);
}

void Fixed::setRawBits(const int raw) {
	this->_number = raw;
}

int Fixed::toInt() const {
	return (this->_number / (1 << this->_number_fractional_bits));
}

float Fixed::toFloat() const {
	return ((float)this->_number / (float)(1 << this->_number_fractional_bits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

/* Operator cmp */
bool Fixed::operator>(const Fixed &other) {return (toFloat() > other.toFloat());}
bool Fixed::operator<(const Fixed &other) {return (toFloat() < other.toFloat());}
bool Fixed::operator<=(const Fixed &other) {return (toFloat() <= other.toFloat());}
bool Fixed::operator>=(const Fixed &other) {return (toFloat() >= other.toFloat());}
bool Fixed::operator==(const Fixed &other) {return (toFloat() == other.toFloat());}
bool Fixed::operator!=(const Fixed &other) {return (toFloat() != other.toFloat());}
