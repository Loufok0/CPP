#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {};
ScalarConverter::~ScalarConverter(void) {};

void ScalarConverter::convert(const std::string literal)
{

	char type = getType(literal);
	std::cout << RED << type << RESET << std::endl;
	if (type == 'E')
	{
		std::cout << RED << "ERROR: Unrecognised type for " << literal << RESET << std::endl;
		return ;
	}

	if (type == '8')
		diplayInf(literal);
	else if (type == 'n')
		diplayNan(literal);
	else if (type == 'c')
	{
		std::cout << "char: ";
		if (!isprint(literal[0]))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << literal[0] << std::endl;
	
		std::cout << "int: " << (int)literal[0] << std::endl;
		std::cout << "float: " << (float)literal[0] << ".0f" << std::endl;
		std::cout << "double: " << (double)literal[0] << ".0" << std::endl;
	}
	else
	{
		float rest = atof(literal.c_str());
		rest -= floor(rest);
		std::cout << "char: ";
		if (atoi(literal.c_str()) == 127 || (atoi(literal.c_str()) >= 0 && atoi(literal.c_str()) <= 31))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << (char)atoi(literal.c_str()) << std::endl;
	
		if (atof(literal.c_str()) > INT_MAX || atof(literal.c_str()) < INT_MIN)
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << atoi(literal.c_str()) << std::endl;
		if (rest == 0.0)
		{
			std::cout << "float: " << atof(literal.c_str()) << ".0f" << std::endl;
			std::cout << "double: " << atof(literal.c_str()) << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << atof(literal.c_str()) << "f" << std::endl;
			std::cout << "double: " << atof(literal.c_str()) << std::endl;
		}
	}
}

void diplayInf(std::string literal)
{
	std::string str;
	int i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	str = literal.substr(0, 3 + i);
	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << str << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

void diplayNan(std::string literal)
{
	std::string str;
	int i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	str = literal.substr(0, 3 + i);
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << str << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
	// delete str;
	
}

char getType(const std::string literal)
{
	int i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (isdigit(literal[i]))
	{
		if (strchr(literal.c_str(), 'f'))
			return ('f'); //float
		if (strchr(literal.c_str(), '.'))
			return ('d'); //double
		else
			return ('i'); //int
	}
	if (!strncmp(literal.c_str() + i, "nan", 3))
			return ('n'); //nan, nanf, +nan
	if (!strncmp(literal.c_str() + i, "inf", 3))
			return ('8'); //inf, inff, -inf
	if (strlen(literal.c_str()) == 1)
		return ('c'); //char
	return ('E');
}
