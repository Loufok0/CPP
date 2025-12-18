#include "./ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
		return (1);
	}
	// ScalarConverter S; // doesn't work ✓
	ScalarConverter::convert(av[1]);
}

/*
┌─[l @ frigo]-[CPP/cpp_06/ex00]-[ main]-o
└──>./ScalarConverter infffff
8
char: Non displayable
int: inf
float: inff
double: inf
*/
