#ifndef _EASYFIND_H_
# define _EASYFIND_H_

#include <iostream>
#include <vector>
#include <list>

class OutOfRange : public std::exception {
	public:
		virtual const char*    what()const throw();
};
template<typename T>
typename T::iterator easyfind(T container, int nb_find) {
	typedef typename T::iterator iterator;
	iterator it;
	iterator it_end = container.end();

	for (it = container.begin(); it != it_end && *it != nb_find ; ++it );
	if (it != it_end)
		return (it);
	throw ::OutOfRange();
}

#endif