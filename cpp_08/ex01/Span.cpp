#include "Span.hpp"

Span::Span() {
	throw (Span::CppIsShit());
}
Span::Span(unsigned int nMax) :
	_span(std::vector<int>()),
	_nMax(nMax),
	_cursorPos(_nMax) {
}

Span::~Span() {
}

void Span::addNumber(int number) {
	if (_cursorPos == 0)
		throw (Span::toMuchNumber());
	_span.push_back(number);
	_cursorPos--;
}
void Span::addRandomNumberRange(unsigned int start, unsigned int end) {
	if (_cursorPos == 0)
		throw (Span::toMuchNumber());
	for (; end - start != 0 && _cursorPos != 0; start++, _cursorPos--) {
		_span.push_back(std::rand() % 500);
	}
}

void Span::test_3_nb() {
	std::cout << _span[0] << "\n" << _span[1] << "\n" << _span[2] << std::endl;
}
const char *Span::toMuchNumber::what() const throw() {
	return ("Too much number in this span");
}
const char *Span::CppIsShit::what() const throw() {
	return ("cpp is shit we need a default constructor but it dosen't make sense");
}