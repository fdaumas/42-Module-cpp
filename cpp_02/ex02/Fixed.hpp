#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(int int_number);
	Fixed(float float_number);
	Fixed(const Fixed &fixed);
	~Fixed();

	Fixed&operator=(const Fixed &fixed);

	bool operator>(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator>=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _number ;
	const static int _number_fractional_bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
