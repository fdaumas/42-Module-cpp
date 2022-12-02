#include "Litteral.hpp"

Litteral::Litteral(const std::string& value) :
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
			throw (Litteral::badValue());
		}
	}
}

Litteral &Litteral::operator=(const Litteral& copy) {
	if (this == &copy)
		return (*this);
	return (*this);
}

Litteral::Litteral(const Litteral &copy) : _value(copy._value) {}

Litteral::~Litteral() {}

bool Litteral::isNan() const {
	return (_value == "nan" || _value == "nanf");
}

bool Litteral::isInf() const {
	return (_value == "-inf" || _value == "-inff" || _value == "+inf"
		|| _value == "+inff" || _value == "inf" || _value == "inff");
}

bool Litteral::isChar() const {
	try {
		int value = std::atoi(this->_value.c_str());
		if (value > 31 && value < 127)
			return (true);
	}
	catch (...) {
		return (false);
	}
	return (false);
}

void Litteral::print() const {
	if (isNan())
		return (printNan());
	if (isChar()) {
		int value_char = stoi(_value);
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

void Litteral::printNan() const {
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: nanf" << std::endl
		<< "double: nan" << std::endl;
}

void Litteral::printInf() const {
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

void Litteral::otherPrint() const {
	if (_isInt) {
		int integer = std::atoi(this->_value.c_str());
		std::cout << "int: " << static_cast<int>(integer) << std::endl
			<< "float: " << static_cast<float>(integer) << ".0f" << std::endl
			<< "double: " << static_cast<double>(integer) << ".0" << std::endl;
	}
	else if (_isFloat) {
		float floater = std::atof(this->_value.c_str());
		std::cout << "int: " << static_cast<int>(floater) << std::endl
			<< "float: " << static_cast<float>(floater) << "f" << std::endl;// TODO dosen't print .0 with x.0f
		std::cout << "double: " << static_cast<double>(floater) << std::endl; // TODO dosen't print .0 with x.0f
	}
}

const char* Litteral::badValue::what() const throw() {
	return ("Bad Value");
}