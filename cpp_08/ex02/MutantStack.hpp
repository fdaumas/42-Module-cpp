#ifndef _MUTANTSTACK_H_
# define _MUTANTSTACK_H_

#include <iostream>
#include <stack>
#include <list>

template<class T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack<T> const & cp) : std::stack<T>(cp) {}
		~MutantStack() {}
		MutantStack &operator=(MutantStack<T> const & cp) {
			*this == cp;
			return (*this);
		}

		iterator begin() { return (std::stack<T>::c.begin()); }
		iterator end() { return (std::stack<T>::c.end()); }
		const_iterator const_begin() { return ( std::stack<T>::c.begin()); }
		const_iterator const_end() { return ( std::stack<T>::c.end()); }
};

#endif