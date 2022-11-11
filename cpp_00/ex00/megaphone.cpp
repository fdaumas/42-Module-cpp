#include <iostream>

void	str_toupper(char *str)
{
	int	index = 0;

	while (str[index])
		std::cout << (char)toupper(str[index++]);
}

int		main(int argc, char *argv[])
{
	int	index_arg = 1;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(index_arg < argc) {
		str_toupper(argv[index_arg]);
		index_arg++;
	}
	std::cout << std::endl;
	return (0);
}