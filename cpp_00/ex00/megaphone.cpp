#include <iostream>

int	main(int ac, char **av)
{
	int	i = 0;
	int	n = 1;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (n < ac)
	{
		i = 0;
		while (av[n][i])
		{
			std::cout << (char)std::toupper(av[n][i]);
			i++;
		}
		n++;
	}
}
