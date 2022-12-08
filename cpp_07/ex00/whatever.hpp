#ifndef _WHATEVER_H_
# define _WHATEVER_H_

#include <iostream>

template<class  T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}
template<class  T>
T const & min(T const & a, T const & b) {
	return (b <= a ? b : a);
}
template<class  T>
T const & max(T const & a, T const & b) {
	return (b >= a ? b : a);
}

#endif