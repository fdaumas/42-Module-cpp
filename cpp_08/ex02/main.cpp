#include "MutantStack.hpp"

int main() {
//###########################################################################//
	{
		std::cout << "### own test ###" << std::endl;
		MutantStack<int> stack_int;

		stack_int.push(45);
		stack_int.push(42);
		std::cout << stack_int.top() << std::endl;
		std::cout << std::endl;
		MutantStack<int>::iterator it = stack_int.begin();
		MutantStack<int>::iterator it_end = stack_int.end();
		while (it != it_end) {
			std::cout << *it << std::endl;
			it++;
		}
		std::cout << std::endl;
		MutantStack<int>::const_iterator const_it = stack_int.const_begin();
		MutantStack<int>::const_iterator const_it_end = stack_int.const_end();
		while (const_it != const_it_end) {
		std::cout << *const_it << std::endl;
			const_it++;
		}
		std::cout << std::endl;
		*it = 1;
		std::cout << *const_it << std::endl;
		std::cout << std::endl;
	}
//###########################################################################//
	{
		std::cout << "### subject test ###" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
//###########################################################################//
	{
		std::cout << "### subject test list ###" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << lst.front() << std::endl;
		lst.pop_back();
		std::cout << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		//[...]
		lst.push_back(0);
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(lst);
	}
}