#include "./btc.hpp"

Btc::Btc(void) : _inputName("./input.txt"), _dataName("./data.csv") {}
Btc::Btc(std::string input, std::string data) : _inputName(input), _dataName(data) {}

Btc::~Btc(void) {}

void Btc::printFile(std::string name)
{
	std::ifstream	file(name.c_str());
	std::string	text;

	std::cout << BLUE << "READING FILE " << name << ":"<< RESET << std::endl;
	while (true)
	{
		getline(file, text);

		if (file.eof())
			break ;
		else if (file.fail() || file.bad())
		{
			std::cout << ERROR << "Error while reading file" << std::endl;
			return ;
		}
		else
			std::cout << text << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void Btc::parseInput(void)
{
	std::ifstream	file(_inputName.c_str());
	std::string	line;

	while (std::getline(file, line))
	{
		size_t pos = line.find(" | ");

		if (pos == std::string::npos)
		{
			std::cout << ERROR << "Bad input => " << line << std::endl;
			continue;
		}

		std::string key = line.substr(0, pos);
		std::string value = line.substr(pos + 3);

		std::stringstream ss(value);
		float f;
		ss >> f;
		_input.insert(std::make_pair(key, f));


		// std::cout << "Key: " << key << " Value: " << value << std::endl;
	}
}

void Btc::parseData(void)
{
	std::ifstream	file(_dataName.c_str());
	std::string	line;

	while (std::getline(file, line))
	{
		size_t pos = line.find(",");

		if (pos == std::string::npos)
		{
			std::cout << ERROR << "Bad input => " << line << std::endl;
			continue;
		}

		std::string key = line.substr(0, pos);
		std::string value = line.substr(pos + 1);

		std::stringstream ss(value);
		float f;
		ss >> f;
		_data.insert(std::make_pair(key, f));


		// std::cout << "Key: " << key << " Value: " << value << std::endl;
	}
}


void Btc::printData(void)
{
	std::multimap<std::string, float>::iterator it = _input.begin();
	while (it != _input.end())
	{
		std::cout << it->first << " :::::::: " << it->second << std::endl;
		it++;
	}
}
