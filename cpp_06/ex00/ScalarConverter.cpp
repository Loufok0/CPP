#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {};
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;};
ScalarConverter& ScalarConverter::operator = (const ScalarConverter &other) {(void)other; return (*this);};
ScalarConverter::~ScalarConverter(void) {};

void ScalarConverter::convert(const std::string literal)
{

	char type = getType(literal);
	std::cout << RED << "Type: " << type << RESET << std::endl;
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
		if (!isprint(static_cast<char>(literal.c_str()[0])))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << literal[0] << std::endl;
	
		std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(literal[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(literal[0]) << ".0" << std::endl;
	}
	else
	{
		float rest = atof(literal.c_str());
		rest -= floor(rest);
		std::cout << "char: ";
		int value = atoi(literal.c_str());
		
		if (value < 0 || value > 127)
			std::cout << "impossible" << std::endl;
		else if (!isprint(value))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "" << static_cast<char>(value) << std::endl;

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


bool is_number(const std::string& s)
{
	if (s.empty())
		return false;

	int dot_count = 0;
	bool has_digit = false;

	for (size_t i = 0; i < s.size(); ++i)
	{
		if (std::isdigit(s[i]))
		{
			has_digit = true;
		}
		else if (s[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return false;
		}
		else if (s[i] == 'f')
		{
			// 'f' autorisé uniquement à la fin
			return (i == s.size() - 1) && has_digit;
		}
		else
		{
			return false;
		}
	}

	return has_digit;
}

char getType(const std::string literal)
{
	int i = 0;
	if (literal[0] == '+' || literal[0] == '-')
		i++;
	if (is_number(literal))
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
