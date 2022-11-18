#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(int int_number);
	Fixed(float float_number);
	Fixed(const Fixed &fixed);
	~Fixed();

/* Copy Operator */
	Fixed&operator = (const Fixed &fixed);

/* Comparaisons Operator */
	bool operator > (const Fixed &other) const;
	bool operator < (const Fixed &other) const;
	bool operator <= (const Fixed &other) const;
	bool operator >= (const Fixed &other) const;
	bool operator == (const Fixed &other) const;
	bool operator != (const Fixed &other) const;

/* Arithmetics Operator */
	float operator + (const Fixed &other);
	float operator - (const Fixed &other);
	float operator * (const Fixed &other);
	float operator / (const Fixed &other);

/* pre|post increment|decrement Operator */
	Fixed operator ++ ();
	Fixed operator ++ (int);
	Fixed operator -- ();
	Fixed operator -- (int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

	static Fixed& max(Fixed &f1, Fixed &f2);
	static const Fixed& max(const Fixed &f1, const Fixed &f2);
	static Fixed& min(Fixed &f1, Fixed &f2);
	static const Fixed& min(const Fixed &f1, const Fixed &f2);

private:
	int _number ;
	const static int _number_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
std::ostream& operator<(std::ostream& out, const bool boolean);
