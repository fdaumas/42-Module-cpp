#include <stack>
#include <cstdlib>
#include <sstream>
#include <iostream>

int ischarset(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	else if (c == '+' || c == '-' || c == '/' || c == '*')
		return 2;
	else if (c == ' ')
		return 3;
	return 0;
}

bool operation(std::stack<double> *rpn_stack, char c)
{
	double n1, n2;
	if (c == '+')
	{
		n1 = rpn_stack->top();
		rpn_stack->pop();
		n2 = rpn_stack->top();
		rpn_stack->pop();
		rpn_stack->push(n2 + n1);
	}
	else if (c == '-')
	{
		n1 = rpn_stack->top();
		rpn_stack->pop();
		n2 = rpn_stack->top();
		rpn_stack->pop();
		rpn_stack->push(n2 - n1);
	}
	else if (c == '*')
	{
		n1 = rpn_stack->top();
		rpn_stack->pop();
		n2 = rpn_stack->top();
		rpn_stack->pop();
		rpn_stack->push(n2 * n1);
	}
	else if (c == '/')
	{
		if (rpn_stack->top() == 0)
		{
			std::cerr << "Error\nCannot devide by zero" << std::endl;
			return false;
		}
		n1 = rpn_stack->top();
		rpn_stack->pop();
		n2 = rpn_stack->top();
		rpn_stack->pop();
		rpn_stack->push(n2 / n1);
	}
	return true;
}

int main (int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Bad arguments \nUsage ./RPN \"1 2 5 + +\"" << std::endl;  
		return 1;
	}
	std::stack<double> rpn_stack;

	for (int index = 0; argv[1][index]; ++index)
	{
		if (ischarset(argv[1][index]) == 1)
			rpn_stack.push(argv[1][index] - '0');
		else if (ischarset(argv[1][index]) == 2)
		{
			if (rpn_stack.size() < 2)
			{
				std::cout << "Error\nYou don't have 2 numbers in your stack" << std::endl;
				return 3;
			}
			if (!operation(&rpn_stack, argv[1][index]))
				return 3;
		}
		else if (ischarset(argv[1][index]) == 0)
		{
			std::cerr << "Error" << std::endl;
			return 2;
		}
	}
	if (!rpn_stack.empty())
		std::cout << rpn_stack.top() << std::endl;
	return 0;
}
