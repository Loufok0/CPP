#include "sed.hpp"

void	replace(const char *name, std::string text)
{
	std::string fileName = std::string(name) + ".replace";
	std::ofstream	newFile(fileName.c_str(), std::ios_base::app);
	newFile << text << std::endl;
}




void	process(const char *name, std::istream &file)
{
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
			replace(name, text);
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
		process(av[1], file);
	}
}
