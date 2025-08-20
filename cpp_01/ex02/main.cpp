#include <iostream>


int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "address of str: " << &str << std::endl;
	std::cout << "address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "address held by stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "value of str: " << str << std::endl;
	std::cout << "value held by stringPTR: " << *stringPTR << std::endl;
	std::cout << "value held by stringREF: " << stringREF << std::endl;
}
