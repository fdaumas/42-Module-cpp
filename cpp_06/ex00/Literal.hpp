#ifndef _LITERAL_H_
# define _LITERAL_H_

#include <iostream>
#include <iomanip>

class Literal {
	public:
		Literal(const std::string& value);
		Literal(const Literal& copy);
		Literal& operator = (const Literal& copy);
		~Literal();

		bool	isNan() const;
		bool	isInf() const;
		bool	isChar() const;

		void print() const;
		void printInf() const;
		void printNan() const;
		void otherPrint() const;

		class badValue : public std::exception {
			public:
				virtual const char*    what()const throw();
		};

	private:
		bool _isInt;
		bool _isFloat;
		bool _isDouble;
		const std::string& _value;
};

#endif