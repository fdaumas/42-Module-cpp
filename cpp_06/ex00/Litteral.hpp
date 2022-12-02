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
		bool	isInt() const;
		bool	isFloat() const;
		bool	isDouble() const;

		void print() const;
		void printInf() const;
		void printNan() const;

		class badValue : public std::exception {
			public:
				virtual const char*    what()const throw();
		};

	private:
		const std::string& _value;
};

#endif