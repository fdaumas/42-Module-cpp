#include "Span.hpp"

Span::Span() {
	throw (Span::CppIsShit());
}
Span::Span(unsigned int nMax) :
	_span(std::vector<int>()),
	_nMax(nMax),
	_cursorPos(_nMax),
	_size(0) {
}
Span::Span(const Span &cp) :
	_span(std::vector<int>()),
	_nMax(cp._nMax),
	_cursorPos(cp._cursorPos),
	_size(cp._size) {
	for(unsigned int i = 0; i < _size; i++)
		this->_span.push_back(cp._span[i]);
}
Span::~Span() {
}
Span & Span::operator=(const Span & cp) {
	if (this == &cp)
		return (*this);
	this->_span.clear();
	this->_size = cp._size;
	this->_nMax = cp._nMax;
	this->_cursorPos = cp._cursorPos;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_span.push_back(cp._span[i]);
	return (*this);
}

void Span::addNumber(int number) {
	if (_cursorPos == 0)
		throw (Span::toMuchNumber());
	_span.push_back(number);
	_cursorPos--;
	_size++;
}
void Span::addRandomNumberRange(unsigned int start, unsigned int end) {
	if (_cursorPos == 0)
		throw (Span::toMuchNumber());
	for (; end - start != 0 && _cursorPos != 0; start++, _cursorPos--, _size++)
		_span.push_back(std::rand() % 500);
}
int Span::shortestSpan() {
	verificationNumber();
	int min, max, span = INT_MAX;
	for (unsigned int i = 0;  i < _size; i++) {
		for (unsigned int y = i + 1; y < _size; y++) {
			if (_span[i] < _span[y]) {
				min = _span[i];
				max = _span[y];
			}
			else {
				min = _span[y];
				max = _span[i];
			}
			if (max - min < span)
				span = max - min;
		}
	}
	return (span);
}
int Span::longestSpan() {
	verificationNumber();
	return (*std::max_element(_span.begin(), _span.end())
		- *std::min_element(_span.begin(), _span.end()));
}
void Span::test_3_nb() {
	std::cout << _span[0] << "\n" << _span[1] << "\n" << _span[2] << std::endl;
}
void Span::test() {
	int i = 0;
	for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++, i++)
		std::cout << "number " << i <<" = " << *it << std::endl;
}
void Span::verificationNumber() {
	if (_size < 2)
		throw (Span::needMoreNumber());
}
const char *Span::toMuchNumber::what() const throw() {
	return ("Too much number in this span");
}
const char *Span::needMoreNumber::what() const throw() {
	return ("Need 2 or more number");
}
const char *Span::CppIsShit::what() const throw() {
	return ("cpp is shit we need a default constructor but it dosen't make sense");
}