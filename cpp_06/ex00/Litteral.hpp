#ifndef _LITTERAL_H_
# define _LITTERAL_H_

#include <iostream>

class Litteral {
	public:
		Litteral(const std::string& value);
		Litteral(const Litteral& copy);
		Litteral& operator = (const Litteral& copy);
		~Litteral();

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