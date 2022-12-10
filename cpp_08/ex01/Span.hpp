#ifndef _SPAN_H_
# define _SPAN_H_

#include <iostream>
#include <iterator>
#include <vector>

class Span {
	public:
		Span();
		Span(unsigned int nMax);
		Span(const Span & cp);
		Span & operator=(const Span & cp);
		~Span();
		void addNumber(int number);
		void addRandomNumberRange(unsigned int start, unsigned int end);
		void test_3_nb();
		void test() {
			int i = 0;
			for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++, i++)
				std::cout << "number " << i <<" = " << *it << std::endl;
		}
		class CppIsShit : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class toMuchNumber : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
	private:
		std::vector<int> _span;
		unsigned int _nMax;
		unsigned int _cursorPos;

};

#endif
