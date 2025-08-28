#include "sed.hpp"

void	replace(std::string fileName, std::string text, std::string str, std::string rep)
{
	std::ofstream	newFile(fileName.c_str(), std::ios_base::app);
	std::size_t i = 0;
	if (!str[0])
	{
		newFile << text << std::endl;
		return ;
	}
	while (text[i])
	{
		std::size_t found = text.find(str, i);
		if (found == i)
		{
			newFile << rep;
			i += str.length() - 1;
		}
		else
			newFile << text[i];
		i++;
	}
			newFile << std::endl;
}

void	process(const char *name, std::istream &file, std::string str, std::string rep)
{
	std::string		fileName = std::string(name) + ".replace";
	std::ofstream	no(fileName.c_str());
	std::string	text;

	while (true)
	{
		getline(file, text);

		if (file.eof())
			return ;
		else if (file.fail() || file.bad())
		{
			std::cout << "Error reading " << name << " file" << std::endl;
			return ;
		}
		else
			replace(fileName, text, str, rep);
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: <filename> <string to replace> <string to replace by>" << std::endl;
		return (1);
	}

	std::ifstream	file(av[1]);
	if (!file)
	{
		std::cout << "Error openning " << av[1] << " file" << std::endl;
		return (1);
	}
	else
	{
		process(av[1], file, av[2], av[3]);
	}
}
