#ifndef _ITER_H_
# define _ITER_H_

#include <iostream>

template<typename T>
void print(T const & value) {
	std::cout << value << std::endl;
}
template<typename T>
void iter(T * list, int length, void f(T const & value)) {
	int index = 0;
	while (index < length) {
		f(list[index]);
		index++;
	}
}

#endif