#ifndef _ARRAY_H_
# define _ARRAY_H_

#include <iostream>

template<typename T>
class Array {
	public:
		Array() : _array(nullptr), _size(0) {
		}
		Array(unsigned int nb_element) : _size(nb_element) {
			_array = new T[_size]();
		}
		Array(const Array & cp) : _size(cp._size) {
			_array = new T[cp._size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = cp._array[i];
		}
		Array & operator=(const Array & cp) {
			if (this != &cp) {
				_size = cp._size;
				if (this->_array != nullptr)
					delete [] this->_array;
				if (cp._array == nullptr) {
					_array = nullptr;
				}
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = cp._array[i];
				return (*this);
			}
			return (*this);
		}
		~Array() {
			if (_size > 0)
				delete [] _array;
		}
		unsigned int size() const {
			return (_size);
		}
		class OutOfRange : public std::exception {
			public:
				virtual const char*    what()const throw() {
					return ("Out of range");
				}
		};
		T & operator[](unsigned int number) {
			if (number >= _size)
				throw (OutOfRange());
			return (_array[number]);
		}
		const T & operator[](unsigned int number) const{
			if (number >= _size)
				throw (OutOfRange());
			return (_array[number]);
		}
	private:
		T * _array;
		unsigned int _size;
};

#endif