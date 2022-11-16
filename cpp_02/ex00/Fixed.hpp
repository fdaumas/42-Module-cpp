#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed&operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _number ;
	static const int _number_fractional_bits = 8;
};