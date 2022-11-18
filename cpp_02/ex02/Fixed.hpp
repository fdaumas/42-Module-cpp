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
	bool operator > (const Fixed &other);
	bool operator < (const Fixed &other);
	bool operator <= (const Fixed &other);
	bool operator >= (const Fixed &other);
	bool operator == (const Fixed &other);
	bool operator != (const Fixed &other);

/* Arithmetics Operator */
	float operator + (const Fixed &other);
	float operator - (const Fixed &other);
	float operator * (const Fixed &other);
	float operator / (const Fixed &other);

/* pre|post increment|decrement Operator */
	float operator ++ ();
	float operator ++ (int );
	float operator -- ();
	float operator -- (int );

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _number ;
	const static int _number_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
std::ostream& operator<(std::ostream& out, const bool boolean);
