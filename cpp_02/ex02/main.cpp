#include "Fixed.hpp"

int main( void ) {
	std::cout << "----------SUBJECT MAIN--------------" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "----------MY COMPLAIMENTARY MAIN--------------" << std::endl;
	Fixed integer(10);
	Fixed same_int(10);
	Fixed floater(10.10f);
	Fixed same_float(10.10f);
	std::cout << "----------TEST COMPARAISON DIFFERENT NUMBER (FLOATER > INT)--------------" << std::endl;
	((std::cout << "integer > floater ") < (integer > floater)) << std::endl ;
	((std::cout << "integer < floater ") < (integer < floater)) << std::endl ;
	((std::cout << "integer >= floater ") < (integer >= floater)) << std::endl ;
	((std::cout << "integer <= floater ") < (integer <= floater)) << std::endl ;
	((std::cout << "integer == floater ") < (integer == floater)) << std::endl ;
	((std::cout << "integer != floater ") < (integer != floater)) << std::endl ;
	std::cout << "----------TEST COMPARAISON SAME INT--------------" << std::endl;
	((std::cout << "integer > same_int ") < (integer > same_int)) << std::endl ;
	((std::cout << "integer < same_int ") < (integer < same_int)) << std::endl ;
	((std::cout << "integer >= same_int ") < (integer >= same_int)) << std::endl ;
	((std::cout << "integer <= same_int ") < (integer <= same_int)) << std::endl ;
	((std::cout << "integer == same_int ") < (integer == same_int)) << std::endl ;
	((std::cout << "integer != same_int ") < (integer != same_int)) << std::endl ;
	std::cout << "----------TEST COMPARAISON SAME FLOAT--------------" << std::endl;
	((std::cout << "floater > same_float ") < (floater > same_float)) << std::endl ;
	((std::cout << "floater < same_float ") < (floater < same_float)) << std::endl ;
	((std::cout << "floater >= same_float ") < (floater >= same_float)) << std::endl ;
	((std::cout << "floater <= same_float ") < (floater <= same_float)) << std::endl ;
	((std::cout << "floater == same_float ") < (floater == same_float)) << std::endl ;
	((std::cout << "floater != same_float ") < (floater != same_float)) << std::endl ;
	std::cout << "----------TEST COMPARAISON SAME INT - FLOAT--------------" << std::endl;
	Fixed same_integer(10);
	Fixed same_floater(10.0f);
	((std::cout << "same_integer > same_floater ") < (same_integer > same_floater)) << std::endl ;
	((std::cout << "same_integer < same_floater ") < (same_integer < same_floater)) << std::endl ;
	((std::cout << "same_integer >= same_floater ") < (same_integer >= same_floater)) << std::endl ;
	((std::cout << "same_integer <= same_floater ") < (same_integer <= same_floater)) << std::endl ;
	((std::cout << "same_integer == same_floater ") < (same_integer == same_floater)) << std::endl ;
	((std::cout << "same_integer != same_floater ") < (same_integer != same_floater)) << std::endl ;
	std::cout << "----------TEST ARITHMETICS--------------" << std::endl;
	std::cout << "integer + integer = " << integer + integer << std::endl;
	std::cout << "integer - integer = " << integer - integer << std::endl;
	std::cout << "integer * integer = " << integer * integer << std::endl;
	std::cout << "integer / integer = " << integer / integer << std::endl;
	std::cout << "----------TEST MAX MIN--------------" << std::endl;
	std::cout << "integer | floater max = " <<Fixed::max(integer, floater) << std::endl;
	std::cout << "integer | floater min = " << Fixed::min(integer, floater) << std::endl;

	return 0;
}