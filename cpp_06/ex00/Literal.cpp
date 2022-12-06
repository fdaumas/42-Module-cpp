#include "Literal.hpp"

Literal::Literal(const std::string& value) :
	_isInt(true),
	_isFloat(false),
	_isDouble(false),
	_value(value)
{
	if (isNan() || isInf())
		return ;
	int index = 0, nb_point = 0;
	if (value[index] == '-')
		index++;
//	if (std::atof(_value.c_str()) > 2147483647) {
//		std::cerr << "value > INT MAX " << std::endl;
//		throw (Literal::badValue());
//	}
//	if (std::atof(_value.c_str()) < -2147483648) {
//		std::cerr << "value < INT MIN " << std::endl;
//		throw (Literal::badValue());
//	}
	while(value[index])
	{
		if (value[index] >= '0' && value[index] <= '9')
			index++;
		else if (value[index] == 'f' && value[index + 1] == '\0'
			&& nb_point == 1) {
			this->_isFloat = true;
			this->_isDouble = false;
			break;
		}
		else if (value[index] == '.' && nb_point == 0
			&& value[index + 1] != '\0') {
			nb_point++;
			index++;
			this->_isInt = false;
			this->_isDouble = true;
		}
		else {
			throw (Literal::badValue());
		}
	}
}

Literal &Literal::operator=(const Literal& copy) {
	if (this == &copy)
		return (*this);
	return (*this);
}

Literal::Literal(const Literal &copy) : _value(copy._value) {}

Literal::~Literal() {}

bool Literal::isNan() const {
	return (_value == "nan" || _value == "nanf");
}

bool Literal::isInf() const {
	return (_value == "-inf" || _value == "-inff" || _value == "+inf"
		|| _value == "+inff" || _value == "inf" || _value == "inff");
}

bool Literal::isChar() const {
	int value = std::atoi(this->_value.c_str());
	if (value > 31 && value < 127)
		return (true);
	return (false);
}

void Literal::print() const {
	if (isNan())
		return (printNan());
	if (isChar()) {
		int value_char = atoi(_value.c_str());
		std::cout << "char: '"
			<< static_cast<char>(value_char) << "'" << std::endl;
	}
	else {
		std::cout << "char: Non displayable" << std::endl;
	}
	if(isInf())
		return (printInf());
	otherPrint();
}

void Literal::printNan() const {
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: nanf" << std::endl
		<< "double: nan" << std::endl;
}

void Literal::printInf() const {
	if (_value == "inf" || _value == "+inf") {
		std::cout << "int: impossible" << std::endl
			<< "float: inff" << std::endl
			<< "double: inf" << std::endl;
	}
	else {
		std::cout << "int: impossible" << std::endl
				  << "float: -inff" << std::endl
				  << "double: -inf" << std::endl;
	}
}

void Literal::otherPrint() const {
	if (_isInt) {
		int integer = std::atoi(this->_value.c_str());
		if (isValidInt())
			std::cout << "int: " << static_cast<int>(integer)
				<< "\nfloat: " << static_cast<float>(integer) << ".0f\n"
				<< "double: " << static_cast<double>(integer) << ".0" << std::endl;
		else
			std::cout << "int: Impossible\nfloat: " << static_cast<float>(integer) << ".0f\n"
				  << "double: " << static_cast<double>(integer) << ".0" << std::endl;
	}
	else if (_isFloat) {
		std::cout << std::fixed << std::setprecision(findPrecision() - 2);
		float floater = std::atof(this->_value.c_str());
		if (isValidInt())
			std::cout << "int: " << static_cast<int>(floater)
				<< "\nfloat: " << static_cast<float>(floater) << "f\n"
				<< "double: " << static_cast<double>(floater) << std::endl;
		else
			std::cout << "int: Impossible\nfloat: "
				<< static_cast<float>(floater) << "f\n"
				<< "double: " << static_cast<double>(floater) << std::endl;
	}
	else if (_isDouble) {
		std::cout << std::fixed << std::setprecision(findPrecision() - 1);
		double nb_double = std::atof(this->_value.c_str());
		if (isValidInt())
			std::cout << "int: " << static_cast<int>(nb_double)
				<< "\nfloat: "  << static_cast<float>(nb_double) << "f\n"
				<< "double: " << static_cast<double>(nb_double) << std::endl;
		else
			std::cout << "int: Impossible\nfloat: "
				<< static_cast<float>(nb_double) << "f\n"
				<< "double: " << static_cast<double>(nb_double) << std::endl;
	}
}

int Literal::findPrecision() const {
	int index_str = 0, length_after_point = 0;
	while (_value[index_str] != '.')
		index_str++;
	while(_value[index_str + length_after_point])
		length_after_point++;
	return length_after_point;
}

bool Literal::isValidInt() const {
	if (std::atof(_value.c_str()) >= 2147483648 || std::atof(_value.c_str()) <= -2147483649) {
		return (false);
	}
	return (true);
}

const char* Literal::badValue::what() const throw() {
	return ("Bad Value");
}