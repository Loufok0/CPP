#include "./btc.hpp"

Btc::Btc(void) : _input("./input.txt"), _data("./data.csv") {}
Btc::Btc(std::string input, std::string data) : _input(input), _data(data) {}

Btc::~Btc(void) {}

void Btc::printInput(void)
{
	std::ifstream	input(_input.c_str());
	std::string	text;

	std::cout << BLUE << "INPUT FILE:" << RESET << std::endl;
	while (true)
	{
		getline(input, text);

		if (input.eof())
			break ;
		else if (input.fail() || input.bad())
		{
			std::cout << ERROR << "Error while reading file" << std::endl;
			return ;
		}
		else
			std::cout << text << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Btc::printData(void)
{
	std::ifstream	data(_data.c_str());
	std::string	text;

	std::cout << BLUE << "INPUT FILE:" << RESET << std::endl;
	while (true)
	{
		getline(data, text);

		if (data.eof())
			break ;
		else if (data.fail() || data.bad())
		{
			std::cout << ERROR << "Error while reading file" << std::endl;
			return ;
		}
		else
			std::cout << text << std::endl;
	}
	std::cout << std::endl << std::endl;
}
